utils/hsc2hs_dist_VERSION = 0.67
utils/hsc2hs_dist_MODULES = Main HSCParser DirectCodegen CrossCodegen UtilsCodegen Common C Flags
utils/hsc2hs_dist_HIDDEN_MODULES = HSCParser DirectCodegen CrossCodegen UtilsCodegen Common C Flags
utils/hsc2hs_dist_SYNOPSIS =A preprocessor that helps with writing Haskell bindings to C code
utils/hsc2hs_dist_HS_SRC_DIRS = .
utils/hsc2hs_dist_DEPS = base-4.3.1.0 containers-0.4.0.0 directory-1.1.0.0 process-1.0.1.5
utils/hsc2hs_dist_DEP_NAMES = base containers directory process
utils/hsc2hs_dist_INCLUDE_DIRS = 
utils/hsc2hs_dist_INCLUDES = 
utils/hsc2hs_dist_INSTALL_INCLUDES = 
utils/hsc2hs_dist_EXTRA_LIBRARIES = 
utils/hsc2hs_dist_EXTRA_LIBDIRS = 
utils/hsc2hs_dist_C_SRCS  = 
utils/hsc2hs_dist_CMM_SRCS  := $(addprefix cbits/,$(notdir $(wildcard utils/hsc2hs/cbits/*.cmm)))
utils/hsc2hs_dist_DATA_FILES = template-hsc.h
utils/hsc2hs_dist_HC_OPTS = -XHaskell98 -XCPP -XForeignFunctionInterface
utils/hsc2hs_dist_CC_OPTS = 
utils/hsc2hs_dist_CPP_OPTS = 
utils/hsc2hs_dist_LD_OPTS = 
utils/hsc2hs_dist_DEP_INCLUDE_DIRS_SINGLE_QUOTED = '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/process-1.0.1.5/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/directory-1.1.0.0/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/unix-2.4.2.0/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/old-time-1.0.0.6/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/base-4.3.1.0/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/include'
utils/hsc2hs_dist_DEP_CC_OPTS = 
utils/hsc2hs_dist_DEP_LIB_DIRS_SINGLE_QUOTED = '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/process-1.0.1.5' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/directory-1.1.0.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/unix-2.4.2.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/old-time-1.0.0.6' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/old-locale-1.0.0.2' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/filepath-1.2.0.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/containers-0.4.0.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/array-0.3.0.2' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/base-4.3.1.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/integer-gmp-0.2.0.3' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/ghc-prim-0.2.0.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2'
utils/hsc2hs_dist_DEP_EXTRA_LIBS = rt util dl gmp m rt dl
utils/hsc2hs_dist_DEP_LD_OPTS = 
utils/hsc2hs_dist_BUILD_GHCI_LIB = YES

$(eval $(utils/hsc2hs_PACKAGE_MAGIC))
