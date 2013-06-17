#								 -*-makefile-*-
# mk/config.mk.  Generated from config.mk.in by configure.
#
################################################################################
#
# config.mk.in
#
# This file supplies defaults for many tweakable build configuration
# options.  Some of the defaults are filled in by the autoconf-generated
# configure script.
#
# DO NOT EDIT THIS FILE!
#
# 	- config.mk is auto-generated from config.mk.in by configure.
#	  If you edit config.mk your changes will be spammed.
#
#	- Settings in this file may be overriden by giving replacement
#	  definitions in build.mk.  See build.mk.sample for a good
#	  starting point for a build.mk file.
#
#	  If you don't have a build.mk file then you get defaults for everything.
#	  The defaults should provide a reasonable vanilla build.

# TOP: the top of the fptools hierarchy, absolute path.
# On Windows this is a c:/foo/bar style path.
TOP		= /home/guillo_e/Downloads/ghc-7.4.2

include $(TOP)/mk/project.mk

################################################################################
#
#		Global configuration options
#
################################################################################

# BootingFromHc - build GHC and the libraries from .hc files?
# (unregisterised only)
BootingFromHc = NO

NO_INCLUDE_DEPS = NO
NO_INCLUDE_PKGDATA = NO

# Should we build latex docs?
LATEX_DOCS = NO

# Mac OS X deployment target (to cross-compile for older OS versions)
#
MACOSX_DEPLOYMENT_VERSION = @MACOSX_DEPLOYMENT_VERSION@
MACOSX_DEPLOYMENT_SDK = @MACOSX_DEPLOYMENT_SDK@

ifneq "$(MACOSX_DEPLOYMENT_VERSION)" ""
MACOSX_DEPLOYMENT_CC_OPTS = -mmacosx-version-min=$(MACOSX_DEPLOYMENT_VERSION) \
			    -isysroot $(MACOSX_DEPLOYMENT_SDK) \
			    --no-builtin-fprintf
MACOSX_DEPLOYMENT_LD_OPTS = -mmacosx-version-min=$(MACOSX_DEPLOYMENT_VERSION) \
			    -Wl,-syslibroot,$(MACOSX_DEPLOYMENT_SDK)
# We don't extend SRC_CC_OPTS and friends here directly, as (a) they may get
# overwritten in build.mk and (b) we must not use the deployment options in
# stage 1 or we get a linker error if the bootstrap compiler is for a more 
# recent OS version.
#
# We need --no-builtin-fprintf, as the use of the builtin function optimisation
# for fprintf together with #include "PosixSource" in the RTS leads to the
# use of fwrite$UNIX2003 (with GCC 4.0.1 on Mac OS X 10.5.2).
endif

################################################################################
#
# Variables that control how the compiler itself is built
#
################################################################################

# The compiler used to build GHC is $(GHC).  To change the actual compiler
# used, re-configure with --with-ghc=<path-to-ghc>.

# Extra ways in which to build the compiler (for example, you might want to
# build a profiled compiler so you can see where it spends its time)
GhcCompilerWays=

# Extra option flags to pass to the compiler that compiles the compiler
# (Ones that are essential are wired into compiler/Makefile)
# Typical options to use here:
#
#	-DDEBUG		include debugging code and assertions (will make the
#			compiler slower and produce debugging output, but useful
#			for development)
#
#	-dcore-lint	check the types after every pass of the compiler;
#			a pretty strong internal check of the compiler being
#			used to compile GHC.  Useful when bootstrapping.
GhcHcOpts=-Rghc-timing

# Extra options added to specific stages of the compiler bootstrap.
# These are placed later on the command line, and may therefore
# override options from $(GhcHcOpts).
GhcStage1HcOpts=
GhcStage2HcOpts=-O2
GhcStage3HcOpts=-O2

# These options modify whether or not a built compiler for a bootstrap
# stage defaults to using the new code generation path.  The new
# code generation path is a bit slower, so for development just
# GhcStage2DefaultNewCodegen=YES, but it's also a good idea to try
# building all libraries and the stage2 compiler with the
# new code generator, which involves GhcStage1DefaultNewCodegen=YES.
GhcStage1DefaultNewCodegen=NO
GhcStage2DefaultNewCodegen=NO
GhcStage3DefaultNewCodegen=NO

GhcDebugged=NO
GhcDynamic=NO

# GhcProfiled=YES means compile a profiled stage-2 compiler
GhcProfiled=NO

# Do we support shared libs?
SharedLibsPlatformList =                        \
    i386-unknown-linux   x86_64-unknown-linux   \
    i386-unknown-freebsd x86_64-unknown-freebsd \
    i386-unknown-openbsd x86_64-unknown-openbsd \
    i386-unknown-netbsd  x86_64-unknown-netbsd  \
    i386-unknown-mingw32                        \
    i386-apple-darwin    x86_64-apple-darwin    powerpc-apple-darwin

ifeq "$(SOLARIS_BROKEN_SHLD)" "NO"
SharedLibsPlatformList += i386-unknown-solaris2
endif

PlatformSupportsSharedLibs = $(if $(filter $(TARGETPLATFORM),\
	$(SharedLibsPlatformList)),YES,NO)

# Build a compiler that will build *unregisterised* libraries and
# binaries by default.  Unregisterised code is supposed to compile and
# run without any support for architecture-specific assembly mangling,
# register assignment or tail-calls, and is therefore a good way to get
# started when porting GHC to new architectures.
#
# NOTE: the stage1 compiler will be a registerised binary (assuming
# the compiler you build with is generating registerised binaries), but
# the stage2 compiler will be an unregisterised binary.
#
ifneq "$(findstring $(HostArch_CPP), i386 x86_64 powerpc arm)" ""
GhcUnregisterised=NO
else
GhcUnregisterised=YES
endif

# Build a compiler with a native code generator backend
# (as well as a C backend)
#
# Target platforms supported:
#   i386, powerpc
#   AIX is not supported 
ArchSupportsNCG=$(strip $(patsubst $(HostArch_CPP), YES, $(findstring $(HostArch_CPP), i386 x86_64 powerpc sparc)))
OsSupportsNCG=$(strip $(patsubst $(HostOS_CPP), YES, $(patsubst aix,,$(HostOS_CPP))))

# lazy test, because $(GhcUnregisterised) might be set in build.mk later.
GhcWithNativeCodeGen=$(strip\
    $(if $(filter YESYESNO,\
		  $(OsSupportsNCG)$(ArchSupportsNCG)$(GhcUnregisterised)),YES,NO))

HaveLibDL = @HaveLibDL@

# ArchSupportsSMP should be set iff there is support for that arch in
# includes/stg/SMP.h
ArchSupportsSMP=$(strip $(patsubst $(HostArch_CPP), YES, $(findstring $(HostArch_CPP), i386 x86_64 sparc powerpc arm)))

# lazy test, because $(GhcUnregisterised) might be set in build.mk later.
GhcWithSMP=$(strip $(if $(filter YESNO, $(ArchSupportsSMP)$(GhcUnregisterised)),YES,NO))

# Whether to include GHCi in the compiler.  Depends on whether the RTS linker
# has support for this OS/ARCH combination.

OsSupportsGHCi=$(strip $(patsubst $(HostOS_CPP), YES, $(findstring $(HostOS_CPP), mingw32 cygwin32 linux solaris2 freebsd dragonfly netbsd openbsd darwin kfreebsdgnu)))
ArchSupportsGHCi=$(strip $(patsubst $(HostArch_CPP), YES, $(findstring $(HostArch_CPP), i386 x86_64 powerpc sparc sparc64 arm)))

ifeq "$(OsSupportsGHCi)$(ArchSupportsGHCi)" "YESYES"
GhcWithInterpreter=YES
else 
GhcWithInterpreter=NO
endif

# GhcEnableTablesNextToCode tells us whether the target architecture
# supports placing info tables directly before the entry code
# (see TABLES_NEXT_TO_CODE in the RTS).  Whether we actually compile for
# TABLES_NEXT_TO_CODE depends on whether we're building unregisterised
# code or not, which may be decided by options to the compiler later.
ifneq "$(findstring $(TargetArch_CPP)X, ia64X powerpc64X)" ""
GhcEnableTablesNextToCode=NO
else
GhcEnableTablesNextToCode=YES
endif

# Whether to use libffi for adjustors (foreign import "wrapper") or
# not.  If we have built-in support (rts/Adjustor.c) then we use that,
# otherwise we fall back on libffi, which is slightly slower.
ArchHasAdjustorSupport = $(if $(findstring $(HostArch_CPP),i386 x86_64),YES,NO)
ifeq "$(ArchHasAdjustorSupport)" "YES"
UseLibFFIForAdjustors=NO
else
UseLibFFIForAdjustors=YES
endif

# On Windows we normally want to make a relocatable bindist, to we
# ignore flags like libdir
ifeq "$(Windows)" "YES"
RelocatableBuild = YES
else
RelocatableBuild = NO
endif

# needs to be after $(RelocatableBuild) is set above
include $(TOP)/mk/install.mk

# When building bindists we set this to yes so that the binaries are as
# portable as possible.
BeConservative = NO

#
# Building various ways?
# (right now, empty if not).
BuildingParallel=$(subst mp,YES,$(filter mp,$(WAYS)))
BuildingGranSim=$(subst mg,YES,$(filter mg,$(WAYS)))

#------------------------------------------------------------------------------
# Options for Libraries

# Which directory (in libraries/) contains the integer library?
INTEGER_LIBRARY=integer-gmp

# We build the libraries at least the "vanilla" way (way "v")
GhcLibWays = v

# In addition to the normal sequential way, the default is to also build
# profiled prelude libraries unless we are booting from .hc files
ifneq "$(BootingFromHc)" "YES"
GhcLibWays += p
endif

ifeq "$(PlatformSupportsSharedLibs)" "YES"
GhcLibWays += dyn
endif

# Handy way to test whether we're building shared libs or not.
BuildSharedLibs=$(strip $(if $(findstring dyn,$(GhcLibWays)),YES,NO))

# In addition, the RTS is built in some further variations.  Ways that
# make sense here:
# 
#   thr         : threaded
#   thr_p       : threaded profiled
#   debug       : debugging (compile with -g for the C compiler, and -DDEBUG)
#   debug_p     : debugging profiled
#   thr_debug   : debugging threaded
#   thr_debug_p : debugging threaded profiled
#   l           : event logging
#   thr_l       : threaded and event logging
#
GhcRTSWays=l

# Usually want the debug version
ifeq "$(BootingFromHc)" "NO"
GhcRTSWays += debug 
endif

# Want the threaded versions unless we're unregisterised
# Defer the check until later by using $(if..), because GhcUnregisterised might
# be set in build.mk, which hasn't been read yet.
GhcRTSWays += $(if $(findstring NO, $(GhcUnregisterised)),thr thr_debug thr_l,)
GhcRTSWays += $(if $(findstring p, $(GhcLibWays)),$(if $(findstring NO, $(GhcUnregisterised)),thr_p,),)
GhcRTSWays += $(if $(findstring dyn, $(GhcLibWays)), dyn debug_dyn $(if $(findstring NO, $(GhcUnregisterised)),thr_dyn thr_debug_dyn),)

# We can only build GHCi threaded if we have a threaded RTS:
GhcThreaded = $(if $(findstring thr,$(GhcRTSWays)),YES,NO)

# Option flags to pass to GHC when it's compiling modules in
# fptools/libraries.  Typically these are things like -O or
# -dcore-lint or -H32m.  The ones that are *essential* are wired into
# the build system.
#
# 	-O(2) is pretty desirable, otherwise no inlining of prelude
#		things (incl "+") happens when compiling with this compiler

GhcLibHcOpts=-O2

# Strip local symbols from libraries?  This can make the libraries smaller,
# but makes debugging somewhat more difficult.  Doesn't work with all ld's.
#
StripLibraries=NO

# These are the URL patterns that Haddock uses to generate the "Source
# File" links on each page.
PackageSourceURL = http://darcs.haskell.org/packages/$(PACKAGE)/%{FILE}

# ----------------------------------------------------------------------------
# Object-file splitting
#
# 	Set SplitObjs=YES or NO in your build.mk
#
#	Don't use -split-objs in in GhcLibHcOpts, because the build
#		system needs to do other special magic if you are
#		doing object-file splitting

ArchSupportsSplitObjs=$(strip $(if $(filter $(TargetArch_CPP),i386 x86_64 powerpc sparc),YES,NO))
OsSupportsSplitObjs=$(strip $(if $(filter $(TargetOS_CPP),mingw32 cygwin32 linux darwin solaris2 freebsd dragonfly netbsd openbsd),YES,NO))
SplitObjsBroken = @SplitObjsBroken@

# lazy test, so that $(GhcUnregisterised) can be set in build.mk
SupportsSplitObjs=$(strip \
                    $(if $(and $(filter YES,$(ArchSupportsSplitObjs)),\
                               $(filter YES,$(OsSupportsSplitObjs)),\
                               $(filter NO,$(SplitObjsBroken)),\
                               $(filter NO,$(BootingFromHc)),\
                               $(filter NO,$(GhcUnregisterised))),\
                          YES,NO))

# By default, enable SplitObjs for the libraries if this build supports it
SplitObjs=$(SupportsSplitObjs)

# ----------------------------------------------------------------------------
# Package-related things

# Extra packages to add to the build, in dependency order
EXTRA_PACKAGES =

# Whether to install $(EXTRA_PACKAGES)
InstallExtraPackages = NO

# Run "ghc-pkg check" on each package
CHECK_PACKAGES = NO

# ----------------------------------------------------------------------------

# There are a number of things which technically depend on GHC (e.g. if
# ghc changes then Haskell files may be compiled differently, or Cabal
# packages may be configured differently). By default we therefore
# have dependencies on the compiler executable.

# However, in practice, having a dependency on GHC is just a pain: We
# normally don't want to spend time recompiling other things while
# we're working on the compiler, and even if we did, GHC will normally
# decide compilation isn't needed anyway. So by setting LAX_DEPENDENCIES
# to YES you can turn these dependencies into order-only dependencies,
# i.e. GHC must exist, but if it's newer than other targets then
# rebuilding is not necessary.

LAX_DEPENDENCIES = NO

# ----------------------------------------------------------------------------
# Options for GHC's RTS

# For an optimised RTS (you probably don't want to change these; we build
# a debugging RTS by default now.  Use -debug to get it).
GhcRtsHcOpts=-optc-O2
GhcRtsCcOpts=-fomit-frame-pointer

# Include the front panel code?  Needs GTK+.
GhcRtsWithFrontPanel = NO

# Include support for CPU performance counters via the PAPI library in the RTS?
# (PAPI: http://icl.cs.utk.edu/papi/)
GhcRtsWithPapi = NO
PapiLibDir=
PapiIncludeDir=

################################################################################
#
#		Paths (see paths.mk)
#
################################################################################

# Directory used by GHC (and possibly other tools) for storing
# temporary files.  If your TMPDIR isn't big enough, either override
# this in build.mk or set your environment variable "TMPDIR" to point
# to somewhere with more space.  (TMPDIR=. is a good choice).

# DEFAULT_TMPDIR isn't called TMPDIR because GNU make tends to
# override an environment variable with the value of the make variable
# of the same name (if it exists) when executing sub-processes, so
# setting the TMPDIR env var would have no effect in the build tree.

DEFAULT_TMPDIR		= /tmp
ifeq "$(TARGETPLATFORM)" "i386-unknown-cygwin32"
DEFAULT_TMPDIR		= /C/TEMP
endif
ifeq "$(TARGETPLATFORM)" "i386-unknown-mingw32"
DEFAULT_TMPDIR		= /C/TEMP
endif

BIN_DIST_NAME         = ghc-$(ProjectVersion)
BIN_DIST_PREP_DIR     = bindistprep/$(BIN_DIST_NAME)
BIN_DIST_PREP_TAR     = bindistprep/$(BIN_DIST_NAME)-$(TARGETPLATFORM).tar
BIN_DIST_PREP_TAR_BZ2 = $(BIN_DIST_PREP_TAR).bz2
BIN_DIST_TAR_BZ2      = $(BIN_DIST_NAME)-$(TARGETPLATFORM).tar.bz2
BIN_DIST_LIST         = bindist-list

WINDOWS_INSTALLER_BASE = ghc-$(ProjectVersion)-i386-windows
WINDOWS_INSTALLER = $(WINDOWS_INSTALLER_BASE)$(exeext)

# -----------------------------------------------------------------------------
# Utilities programs: flags 

# If you want to give any standard flags to pretty much any utility
# (see utils.mk for a complete list), by adding a line here
#
# 	SRC_P_OPTS += ...
#
# where P is the utility. For example, to add -O to all Haskell
# compilations, 
#
#	SRC_HC_OPTS += -O


# SRC_HC_OPTS includes flags to be added to *every* Haskell
# compilation.  Setting SRC_HC_OPTS is a good way to set the default
# optimisation level (-O) and heap size (-H<size>).
# 
# SRC_HC_OPTS is *not* for adding flags that are required to make your
# build work.  Examples:
#
#  - instead of using -pgmc/-pgma-/-pgml, use the --with-gcc option to configure
#
#  - if you need -optc, -opta, or -optl flags, the CONF_CC_* and CONF_LD_*
#    variables are more appropriate (set via configure)
#
# Note that SRC_HC_OPTS are added to every Haskell compilation,
# including when using the bootstrapping compiler (stage 0), So don't
# put options here that are only supported by very recent GHCs.
#
SRC_HC_OPTS += -H32m -O

# These flags make flex 8-bit
SRC_FLEX_OPTS	+= -8

# Flags for CPP when running GreenCard on .pgc files
GC_CPP_OPTS += -P -E -x c -traditional -D__GLASGOW_HASKELL__


# -----------------------------------------------------------------------------
# Names of programs in the GHC tree
#
#      xxx_PGM          the name of an executable, without the path
#      xxx              the executable relative to the current dir

GHC_UNLIT_PGM           = unlit$(exeext)
GHC_HP2PS_PGM           = hp2ps$(exeext)
GHC_GHCTAGS_PGM         = ghctags$(exeext)
GHC_HSC2HS_PGM          = hsc2hs$(exeext)
GHC_TOUCHY_PGM          = touchy$(exeext)
GHC_SPLIT_PGM           = ghc-split
GHC_SYSMAN_PGM          = SysMan
GHC_GENPRIMOP_PGM       = genprimopcode$(exeext)
GHC_GENAPPLY_PGM        = genapply$(exeext)
GHC_CABAL_PGM           = ghc-cabal$(exeext)
GHC_PKG_PGM             = ghc-pkg$(exeext)
GHC_LTX_PGM             = ltx$(exeext)
GHC_MKDIRHIER_PGM       = mkdirhier
GHC_LNDIR_PGM           = lndir

ifeq "$(TARGETPLATFORM)" "i386-unknown-mingw32"
GHC_CP			= "xcopy /y"
GHC_PERL		= perl
else
GHC_CP			= $(CP)
GHC_PERL		= $(PERL)
endif

HP2PS			= $(GHC_HP2PS_DIR)/$(GHC_HP2PS_PGM)
SPLIT			= $(INPLACE_LIB)/$(GHC_SPLIT_PGM)
SYSMAN 			= $(GHC_SYSMAN_DIR)/$(GHC_SYSMAN_PGM)
LTX 			= $(GHC_LTX_DIR)/$(GHC_LTX_PGM)
LNDIR			= $(GHC_LNDIR_DIR)/$(GHC_LNDIR_PGM)

UNLIT			= $(INPLACE_LIB)/$(GHC_UNLIT_PGM)
TOUCHY                  = $(INPLACE_LIB)/$(GHC_TOUCHY_PGM)
MKDIRHIER		= $(INPLACE_BIN)/$(GHC_MKDIRHIER_PGM)
GHC_CABAL_INPLACE	= $(INPLACE_BIN)/$(GHC_CABAL_PGM)
GENAPPLY_INPLACE	= $(INPLACE_BIN)/$(GHC_GENAPPLY_PGM)
GHC_PKG_INPLACE		= $(INPLACE_BIN)/$(GHC_PKG_PGM)
GHCTAGS_INPLACE		= $(INPLACE_BIN)/$(GHC_GHCTAGS_PGM)
HSC2HS_INPLACE		= $(INPLACE_BIN)/$(GHC_HSC2HS_PGM)
GENPRIMOP_INPLACE	= $(INPLACE_BIN)/$(GHC_GENPRIMOP_PGM)

GENERATED_FILE  = chmod a-w
EXECUTABLE_FILE = chmod +x

#-----------------------------------------------------------------------------
# Installed GHC

# $(GHC) points to installed version of the compiler.
#
# NOTE: Don't override $(GHC) in build.mk, use configure --with-ghc instead
# (because the version numbers have to be calculated).

GHC := @WithGhc@
# If we have a make dependency on c:/ghc/ghc, and the file is actually
# called c:/ghc/ghc.exe, then make will think that ghc doesn't exist
# and that it doesn't know how to create it.
ifneq "$(wildcard $(GHC).exe)" ""
GHC := $(GHC).exe
endif

# Sometimes we want to invoke ghc from the build tree in different
# places (eg. it's handy to have a nofib & a ghc build in the same
# tree).  We can refer to "this ghc" as $(GHC_INPLACE):

GHC_INPLACE = $(GHC_STAGE1)

GHC_STAGE0_ABS = $(GHC)
GHC_STAGE1_ABS = $(TOP)/$(INPLACE_BIN)/ghc-stage1$(exeext)
GHC_STAGE2_ABS = $(TOP)/$(INPLACE_BIN)/ghc-stage2$(exeext)
GHC_STAGE3_ABS = $(TOP)/$(INPLACE_BIN)/ghc-stage3$(exeext)

GHC_STAGE0  = $(GHC)
GHC_STAGE1  = $(INPLACE_BIN)/ghc-stage1$(exeext)
GHC_STAGE2  = $(INPLACE_BIN)/ghc-stage2$(exeext)
GHC_STAGE3  = $(INPLACE_BIN)/ghc-stage3$(exeext)

# Install stage 2 by default, can be changed to 3
INSTALL_GHC_STAGE=2

BOOTSTRAPPING_CONF = libraries/bootstrapping.conf

INPLACE_PACKAGE_CONF = $(INPLACE_LIB)/package.conf.d

GhcVersion	= @GhcVersion@
GhcPatchLevel	= @GhcPatchLevel@
GhcMajVersion	= @GhcMajVersion@
GhcMinVersion	= @GhcMinVersion@

# Keep this in sync with the variables in package-config.mk
ghc_ge_613 = @ghc_ge_613@

# Canonicalised ghc version number, used for easy (integer) version
# comparisons.  We must expand $(GhcMinVersion) to two digits by
# adding a leading zero if necessary:
ifneq "$(findstring $(GhcMinVersion), 0 1 2 3 4 5 6 7 8 9)" ""
GhcCanonVersion = $(GhcMajVersion)0$(GhcMinVersion)
else
GhcCanonVersion = $(GhcMajVersion)$(GhcMinVersion)
endif

# Work around #5453, which causes the stage1 compiler to segfault when
# built with 7.2.1.
ifeq "$(GhcVersion)" "7.2.1"
CONF_HC_OPTS_STAGE0 += -fno-full-laziness
compiler/cmm/Bitmap_HC_OPTS += -ffull-laziness
# urgh.  Compiling cmm/Bitmap.hs with -fno-full-laziness results in 
#   "gmp: overflow in mpz type"
# for some unknown reason, so turn full-laziness back on for this module.
endif

#-----------------------------------------------------------------------------
# C compiler
#
# NB. Don't override $(WhatGccIsCalled) using build.mk,  re-configure using
# the flag --with-gcc=<blah> instead.  The reason is that the configure script
# needs to know which gcc you're using in order to perform its tests.

WhatGccIsCalled = /usr/bin/gcc
GccVersion      = 4.6.2
GccLT34         = NO
GccLT46         = NO
CC              = $(WhatGccIsCalled)
CC_STAGE0       = @CC_STAGE0@
CC_STAGE1       = $(CC)
CC_STAGE2       = $(CC)
CC_STAGE3       = $(CC)
AS              = $(WhatGccIsCalled)
AS_STAGE0       = @CC_STAGE0@
AS_STAGE1       = $(AS)
AS_STAGE2       = $(AS)
AS_STAGE3       = $(AS)

# C compiler and linker flags from configure (e.g. -m<blah> to select
# correct C compiler backend). The stage number is the stage of GHC
# that is being used to compile with.
CONF_CC_OPTS_STAGE0 =  -fno-stack-protector
CONF_CC_OPTS_STAGE1 =  -fno-stack-protector
CONF_CC_OPTS_STAGE2 =  -fno-stack-protector
CONF_GCC_LINKER_OPTS_STAGE0 = 
CONF_GCC_LINKER_OPTS_STAGE1 = 
CONF_GCC_LINKER_OPTS_STAGE2 = 
CONF_LD_LINKER_OPTS_STAGE0 = 
CONF_LD_LINKER_OPTS_STAGE1 = 
CONF_LD_LINKER_OPTS_STAGE2 = 
CONF_CPP_OPTS_STAGE0 = 
CONF_CPP_OPTS_STAGE1 = 
CONF_CPP_OPTS_STAGE2 = 

ifeq "$(TARGETPLATFORM)" "ia64-unknown-linux"
CONF_CC_OPTS += -G0
endif

# The .hsc files aren't currently safe for cross-compilation on Windows:
#     libraries\haskeline\.\System\Console\Haskeline\Backend\Win32.hsc:160
#     directive "let" is not safe for cross-compilation
ifneq "$(Windows)" "YES"
SRC_HSC2HS_OPTS += --cross-safe
endif
SRC_HSC2HS_OPTS += $(addprefix --cflag=,$(filter-out -O,$(SRC_CC_OPTS) $(CONF_CC_OPTS_STAGE0)))
SRC_HSC2HS_OPTS += $(foreach d,$(GMP_INCLUDE_DIRS),-I$(d))

#-----------------------------------------------------------------------------
# Mingwex Library
#
HaveLibMingwEx	= @HaveLibMingwEx@
DLLTOOL			= inplace/mingw/bin/dlltool.exe

#-----------------------------------------------------------------------------
# Flex (currently unused, could be moved to glafp-utils)

# FLEX			= @LEX@
# Don't bother with -lfl, we define our own yywrap()s anyway.
# FLEX_LIB		= 
#WAS:FLEX_LIB		= @LEXLIB@

#-----------------------------------------------------------------------------
# Other standard (ha!) Unix utilities

AR			= /usr/bin/ar
AR_OPTS			= q
ArSupportsAtFile = @ArSupportsAtFile@

AR_STAGE0 = @AR_STAGE0@
AR_STAGE1 = $(AR)
AR_STAGE2 = $(AR)
AR_STAGE3 = $(AR)
AR_OPTS_STAGE0 = @AR_OPTS_STAGE0@
AR_OPTS_STAGE1 = $(AR_OPTS)
AR_OPTS_STAGE2 = $(AR_OPTS)
AR_OPTS_STAGE3 = $(AR_OPTS)
EXTRA_AR_ARGS_STAGE0 = $(EXTRA_AR_ARGS)
EXTRA_AR_ARGS_STAGE1 = $(EXTRA_AR_ARGS)
EXTRA_AR_ARGS_STAGE2 = $(EXTRA_AR_ARGS)
EXTRA_AR_ARGS_STAGE3 = $(EXTRA_AR_ARGS)
ArSupportsAtFile_STAGE0 = @ArSupportsAtFile_STAGE0@
ArSupportsAtFile_STAGE1 = $(ArSupportsAtFile)
ArSupportsAtFile_STAGE2 = $(ArSupportsAtFile)
ArSupportsAtFile_STAGE3 = $(ArSupportsAtFile)

CONTEXT_DIFF		= @ContextDiffCmd@
CP			= cp
# It's not easy to separate the CPP program from its flags, as
# AC_PROG_CPP defines CPP as "/usr/bin/gcc -E"
CPP			= /usr/bin/gcc -E 
CTAGS 			= $(ETAGS)
#
# RAWCPP_FLAGS are the flags to give to cpp (viz, gcc -E) to persuade it to
# behave plausibly on Haskell sources.
#
RAWCPP_FLAGS            = -undef -traditional
FIND			= @FindCmd@
SORT		        = @SortCmd@

#
# Sigh - the autoconf macro for INSTALL will subst a relative path to the fallback
# install-sh script (if chosen). This not terribly useful to us, so we convert
# it into an abs. path.
# 
INSTALL			= /usr/bin/install -c
INSTALL			:= $(subst .././install-sh,$(TOP)/install-sh,$(INSTALL))

LATEX			= latex
PDFLATEX                = pdflatex
BIBTEX                  = bibtex
LN_S			= ln -s
MV			= mv
NROFF			= nroff
PERL 			= /usr/bin/perl
PYTHON			= @PythonCmd@
PIC			= pic
RANLIB			= true
SED			= sed
TR 			= tr
SHELL			= /bin/sh

HaveDtrace		= @HaveDtrace@
USE_DTRACE = $(HaveDtrace)
DTRACE			= @DtraceCmd@

LD = @LdCmd@
NM = @NmCmd@

# Some ld's support the -x flag and some don't, so the configure
# script detects which we have and sets LdXFlag to "-x" or ""
# respectively.
LD_X			= @LdXFlag@

# GNU ld supports input via a linker script, which is useful to avoid
# overflowing command-line length limits.
LdIsGNULd		= @LdIsGNULd@

# Set to YES if ld has the --build-id flag.  Sometimes we need to
# disable it with --build-id=none.
LdHasBuildId	        = @LdHasBuildId@

# Set to YES if ld has the --no_compact_unwind flag. See #5019
# and compiler/main/DriverPipeline.hs.
LdHasNoCompactUnwind	= @LdHasNoCompactUnwind@

# On MSYS, building with SplitObjs=YES fails with 
#   ar: Bad file number
# see #3201.  We need to specify a smaller max command-line size
# to work around it.  32767 doesn't work; 30000 does, but says
#     xargs: value for -s option should be < 28153
# so we now use 20000 to be comfortably below this bound
XARGS = xargs
ifeq "$(Windows)" "YES"
XARGS_OPTS = -s 20000
endif

#
# In emergency situations, REAL_SHELL is used to perform shell commands
# from within the ghc driver script, by scribbling the command line to
# a temp file and then having $(REAL_SHELL) execute it. 
#
# The reason for having to do this is that overly long command lines
# cause unnecessary trouble with some shells (e.g., /bin/sh on Solaris
# 2.5.1), which is why this backdoor is provided. The situation of overly
# long command lines is either encountered while doing `make boot' in compiler/, 
# or when linking the compiler binary (`hsc'). 
#
# We do not use SHELL to execute long commands, as `make' will more than likely
# override whatever setting you have in your environment while executing. 

# By default, REAL_SHELL is set equal to SHELL, which is not really a smart move
# as it is SHELL that will show up the bogosity in the first place, but setting
# it to anything else isn't really portable.
#
#  ====> If long command lines cause you trouble, invoke `ghc' (via `make' or otherwise)
# with REAL_SHELL set to something else than /bin/sh, for instance, your favourite
# command shell.
#
REAL_SHELL     = $(SHELL)

STRIP_CMD      = strip
PATCH_CMD      = @PatchCmd@
TAR_CMD        = @TarCmd@
BZIP2_CMD      = bzip2
GZIP_CMD       = gzip

ifeq "$(Windows)" "YES"
TOUCH_CMD      = $(utils/touchy_dist_INPLACE)
TOUCH_DEP      = $(TOUCH_CMD)
else
TOUCH_CMD      = touch
TOUCH_DEP      =
endif

HSCOLOUR_CMD   = @HSCOLOUR@

TIME_CMD       = @TimeCmd@

# GTK+
GTK_CONFIG_CMD = @GTK_CONFIG@

# Set this if you want to use Inno Setup to build a Windows installer
# when you make a bindist
ISCC_CMD       =

#-----------------------------------------------------------------------------
# DocBook XML stuff

BUILD_DOCBOOK_HTML       = @BUILD_DOCBOOK_HTML@
BUILD_DOCBOOK_PS         = @BUILD_DOCBOOK_PS@
BUILD_DOCBOOK_PDF        = @BUILD_DOCBOOK_PDF@
DBLATEX                  = @DblatexCmd@
XSLTPROC                 = @XsltprocCmd@
XMLLINT                  = @XmllintCmd@
HAVE_DOCBOOK_XSL	 = @HAVE_DOCBOOK_XSL@
XSLTPROC_HTML_STYLESHEET = http://docbook.sourceforge.net/release/xsl/current/html/chunk.xsl
XSLTPROC_LABEL_OPTS	 = --stringparam toc.section.depth 3 \
			   --stringparam section.autolabel 1 \
			   --stringparam section.label.includes.component.label 1

#-----------------------------------------------------------------------------
# 		FPtools support software

#
# ghc-pkg
#
GHC_PKG		        = @GhcPkgCmd@

#
# Happy
#
HAPPY			= @HappyCmd@
HAPPY_VERSION		= @HappyVersion@		
#
# Options to pass to Happy when we're going to compile the output with GHC
#
SRC_HAPPY_OPTS		= -agc --strict

#
# Alex
#
ALEX			= @AlexCmd@
ALEX_VERSION		= @AlexVersion@		
Alex3			= @Alex3@
#
# Options to pass to Happy when we're going to compile the output with GHC
#
ifeq "$(Alex3)" "YES"
# We aren't using the Unicode support in Alex 3.0 yet, in fact we do our own
# Unicode handling, so diable Alex's.
SRC_ALEX_OPTS		= -g --latin1
else
SRC_ALEX_OPTS		= -g
endif

# Should we build haddock docs?
HADDOCK_DOCS = YES
# And HsColour the sources?
ifeq "$(HSCOLOUR_CMD)" ""
HSCOLOUR_SRCS = NO
else
HSCOLOUR_SRCS = YES
endif

################################################################################
#
#		31-bit-Int Core files
#
################################################################################

# 
# It is possible to configure the compiler and prelude to support 31-bit
# integers, suitable for a back-end and RTS using a tag bit on a 32-bit
# architecture.  Currently the only useful output from this option is external Core
# files.  The following additions to your build.mk will produce the
# 31-bit core output.  Note that this is *not* just a library "way"; the
# compiler must be built a special way too.

# GhcCppOpts +=-DWORD_SIZE_IN_BITS=31
# GhcLibHcOpts +=-fext-core -fno-code -DWORD_SIZE_IN_BITS=31
# GhcLibCppOpts += -DWORD_SIZE_IN_BITS=31
# SplitObjs=NO

################################################################################
#
#    Library configure arguments
#
################################################################################

CONFIGURE_ARGS = @CONFIGURE_ARGS@

################################################################################
#
#    To be passed to sub-builds
#
################################################################################

ICONV_INCLUDE_DIRS = @ICONV_INCLUDE_DIRS@
ICONV_LIB_DIRS = @ICONV_LIB_DIRS@

GMP_INCLUDE_DIRS = 
GMP_LIB_DIRS = 
