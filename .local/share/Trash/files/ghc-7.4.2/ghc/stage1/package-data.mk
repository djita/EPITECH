ghc_stage1_VERSION = 7.4.2
ghc_stage1_MODULES = Main
ghc_stage1_HIDDEN_MODULES = 
ghc_stage1_SYNOPSIS =XXX
ghc_stage1_HS_SRC_DIRS = .
ghc_stage1_DEPS = array-0.3.0.2 base-4.3.1.0 bytestring-0.9.1.10 directory-1.1.0.0 filepath-1.2.0.0 ghc-7.4.2 process-1.0.1.5 unix-2.4.2.0
ghc_stage1_DEP_NAMES = array base bytestring directory filepath ghc process unix
ghc_stage1_INCLUDE_DIRS = 
ghc_stage1_INCLUDES = 
ghc_stage1_INSTALL_INCLUDES = 
ghc_stage1_EXTRA_LIBRARIES = 
ghc_stage1_EXTRA_LIBDIRS = 
ghc_stage1_C_SRCS  = hschooks.c
ghc_stage1_CMM_SRCS  := $(addprefix cbits/,$(notdir $(wildcard ghc/cbits/*.cmm)))
ghc_stage1_DATA_FILES = settings
ghc_stage1_HC_OPTS = -Wall -XHaskell98 -XCPP -XPatternGuards
ghc_stage1_CC_OPTS = 
ghc_stage1_CPP_OPTS = 
ghc_stage1_LD_OPTS = 
ghc_stage1_DEP_INCLUDE_DIRS_SINGLE_QUOTED = '/home/ian/zz/ghc-7.4.2/compiler/stage1' '/home/ian/zz/ghc-7.4.2/compiler/../libraries/base/cbits' '/home/ian/zz/ghc-7.4.2/compiler/../libraries/base/include' '/home/ian/zz/ghc-7.4.2/compiler/.' '/home/ian/zz/ghc-7.4.2/compiler/parser' '/home/ian/zz/ghc-7.4.2/compiler/utils' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/bytestring-0.9.1.10/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/process-1.0.1.5/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/directory-1.1.0.0/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/unix-2.4.2.0/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/old-time-1.0.0.6/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/base-4.3.1.0/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/include'
ghc_stage1_DEP_CC_OPTS = 
ghc_stage1_DEP_LIB_DIRS_SINGLE_QUOTED = '/home/ian/zz/ghc-7.4.2/compiler/stage1/build' '/home/ian/zz/ghc-7.4.2/libraries/hpc/dist-boot/build' '/home/ian/zz/ghc-7.4.2/libraries/hoopl/dist-boot/build' '/home/ian/zz/ghc-7.4.2/libraries/bin-package-db/dist-boot/build' '/home/ian/zz/ghc-7.4.2/libraries/binary/dist-boot/build' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/bytestring-0.9.1.10' '/home/ian/zz/ghc-7.4.2/libraries/Cabal/Cabal/dist-boot/build' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/process-1.0.1.5' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/pretty-1.0.1.2' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/directory-1.1.0.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/unix-2.4.2.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/old-time-1.0.0.6' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/old-locale-1.0.0.2' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/filepath-1.2.0.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/containers-0.4.0.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/array-0.3.0.2' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/base-4.3.1.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/integer-gmp-0.2.0.3' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/ghc-prim-0.2.0.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2'
ghc_stage1_DEP_EXTRA_LIBS = rt util dl gmp m rt dl
ghc_stage1_DEP_LD_OPTS = 
ghc_stage1_BUILD_GHCI_LIB = YES

$(eval $(ghc_PACKAGE_MAGIC))
