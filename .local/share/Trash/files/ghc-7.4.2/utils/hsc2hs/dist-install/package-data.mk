utils/hsc2hs_dist-install_VERSION = 0.67
utils/hsc2hs_dist-install_MODULES = Main HSCParser DirectCodegen CrossCodegen UtilsCodegen Common C Flags
utils/hsc2hs_dist-install_HIDDEN_MODULES = HSCParser DirectCodegen CrossCodegen UtilsCodegen Common C Flags
utils/hsc2hs_dist-install_SYNOPSIS =A preprocessor that helps with writing Haskell bindings to C code
utils/hsc2hs_dist-install_HS_SRC_DIRS = .
utils/hsc2hs_dist-install_DEPS = base-4.5.1.0 containers-0.4.2.1 directory-1.1.0.2 process-1.1.0.1
utils/hsc2hs_dist-install_DEP_NAMES = base containers directory process
utils/hsc2hs_dist-install_INCLUDE_DIRS = 
utils/hsc2hs_dist-install_INCLUDES = 
utils/hsc2hs_dist-install_INSTALL_INCLUDES = 
utils/hsc2hs_dist-install_EXTRA_LIBRARIES = 
utils/hsc2hs_dist-install_EXTRA_LIBDIRS = 
utils/hsc2hs_dist-install_C_SRCS  = 
utils/hsc2hs_dist-install_CMM_SRCS  := $(addprefix cbits/,$(notdir $(wildcard utils/hsc2hs/cbits/*.cmm)))
utils/hsc2hs_dist-install_DATA_FILES = template-hsc.h
utils/hsc2hs_dist-install_HC_OPTS = -XHaskell98 -XCPP -XForeignFunctionInterface
utils/hsc2hs_dist-install_CC_OPTS = 
utils/hsc2hs_dist-install_CPP_OPTS = 
utils/hsc2hs_dist-install_LD_OPTS = 
utils/hsc2hs_dist-install_DEP_INCLUDE_DIRS_SINGLE_QUOTED = '/home/ian/zz/ghc-7.4.2/libraries/process/include' '/home/ian/zz/ghc-7.4.2/libraries/directory/include' '/home/ian/zz/ghc-7.4.2/libraries/unix/include' '/home/ian/zz/ghc-7.4.2/libraries/old-time/include' '/home/ian/zz/ghc-7.4.2/libraries/containers/include' '/home/ian/zz/ghc-7.4.2/libraries/bytestring/include' '/home/ian/zz/ghc-7.4.2/libraries/array/include' '/home/ian/zz/ghc-7.4.2/libraries/base/include' '/home/ian/zz/ghc-7.4.2/rts/dist/build' '/home/ian/zz/ghc-7.4.2/includes' '/home/ian/zz/ghc-7.4.2/includes/dist-ghcconstants/header' '/home/ian/zz/ghc-7.4.2/includes/dist-derivedconstants/header'
utils/hsc2hs_dist-install_DEP_CC_OPTS = 
utils/hsc2hs_dist-install_DEP_LIB_DIRS_SINGLE_QUOTED = '/home/ian/zz/ghc-7.4.2/libraries/process/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/directory/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/unix/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/old-time/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/old-locale/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/filepath/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/containers/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/deepseq/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/bytestring/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/array/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/base/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/integer-gmp/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/ghc-prim/dist-install/build' '/home/ian/zz/ghc-7.4.2/rts/dist/build'
utils/hsc2hs_dist-install_DEP_EXTRA_LIBS = rt util dl gmp m rt dl
utils/hsc2hs_dist-install_DEP_LD_OPTS = 
utils/hsc2hs_dist-install_BUILD_GHCI_LIB = YES

$(eval $(utils/hsc2hs_PACKAGE_MAGIC))
