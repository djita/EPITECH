libraries/deepseq_dist-install_VERSION = 1.3.0.0
libraries/deepseq_dist-install_MODULES = Control.DeepSeq
libraries/deepseq_dist-install_HIDDEN_MODULES = 
libraries/deepseq_dist-install_SYNOPSIS =Deep evaluation of data structures
libraries/deepseq_dist-install_HS_SRC_DIRS = .
libraries/deepseq_dist-install_DEPS = array-0.4.0.0 base-4.5.1.0
libraries/deepseq_dist-install_DEP_NAMES = array base
libraries/deepseq_dist-install_INCLUDE_DIRS = 
libraries/deepseq_dist-install_INCLUDES = 
libraries/deepseq_dist-install_INSTALL_INCLUDES = 
libraries/deepseq_dist-install_EXTRA_LIBRARIES = 
libraries/deepseq_dist-install_EXTRA_LIBDIRS = 
libraries/deepseq_dist-install_C_SRCS  = 
libraries/deepseq_dist-install_CMM_SRCS  := $(addprefix cbits/,$(notdir $(wildcard libraries/deepseq/cbits/*.cmm)))
libraries/deepseq_dist-install_DATA_FILES = 
libraries/deepseq_dist-install_HC_OPTS = -Wall -XHaskell98 -XCPP
libraries/deepseq_dist-install_CC_OPTS = 
libraries/deepseq_dist-install_CPP_OPTS = 
libraries/deepseq_dist-install_LD_OPTS = 
libraries/deepseq_dist-install_DEP_INCLUDE_DIRS_SINGLE_QUOTED = '/home/ian/zz/ghc-7.4.2/libraries/array/include' '/home/ian/zz/ghc-7.4.2/libraries/base/include' '/home/ian/zz/ghc-7.4.2/rts/dist/build' '/home/ian/zz/ghc-7.4.2/includes' '/home/ian/zz/ghc-7.4.2/includes/dist-ghcconstants/header' '/home/ian/zz/ghc-7.4.2/includes/dist-derivedconstants/header'
libraries/deepseq_dist-install_DEP_CC_OPTS = 
libraries/deepseq_dist-install_DEP_LIB_DIRS_SINGLE_QUOTED = '/home/ian/zz/ghc-7.4.2/libraries/array/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/base/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/integer-gmp/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/ghc-prim/dist-install/build' '/home/ian/zz/ghc-7.4.2/rts/dist/build'
libraries/deepseq_dist-install_DEP_EXTRA_LIBS = gmp m rt dl
libraries/deepseq_dist-install_DEP_LD_OPTS = 
libraries/deepseq_dist-install_BUILD_GHCI_LIB = YES

$(eval $(libraries/deepseq_PACKAGE_MAGIC))
