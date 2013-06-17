libraries/haskell2010_dist-install_VERSION = 1.1.0.1
libraries/haskell2010_dist-install_MODULES = Data.Array Data.Char Data.Complex System.IO System.IO.Error Data.Ix Data.List Data.Maybe Control.Monad Data.Ratio System.Environment System.Exit Numeric Prelude Data.Int Data.Word Data.Bits Foreign Foreign.Ptr Foreign.ForeignPtr Foreign.StablePtr Foreign.Storable Foreign.C Foreign.C.Error Foreign.C.String Foreign.C.Types Foreign.Marshal Foreign.Marshal.Alloc Foreign.Marshal.Array Foreign.Marshal.Error Foreign.Marshal.Utils
libraries/haskell2010_dist-install_HIDDEN_MODULES = 
libraries/haskell2010_dist-install_SYNOPSIS =Compatibility with Haskell 2010
libraries/haskell2010_dist-install_HS_SRC_DIRS = .
libraries/haskell2010_dist-install_DEPS = array-0.4.0.0 base-4.5.1.0 ghc-prim-0.2.0.0
libraries/haskell2010_dist-install_DEP_NAMES = array base ghc-prim
libraries/haskell2010_dist-install_INCLUDE_DIRS = 
libraries/haskell2010_dist-install_INCLUDES = 
libraries/haskell2010_dist-install_INSTALL_INCLUDES = 
libraries/haskell2010_dist-install_EXTRA_LIBRARIES = 
libraries/haskell2010_dist-install_EXTRA_LIBDIRS = 
libraries/haskell2010_dist-install_C_SRCS  = 
libraries/haskell2010_dist-install_CMM_SRCS  := $(addprefix cbits/,$(notdir $(wildcard libraries/haskell2010/cbits/*.cmm)))
libraries/haskell2010_dist-install_DATA_FILES = 
libraries/haskell2010_dist-install_HC_OPTS = -XHaskell98 -XPackageImports -XCPP
libraries/haskell2010_dist-install_CC_OPTS = 
libraries/haskell2010_dist-install_CPP_OPTS = 
libraries/haskell2010_dist-install_LD_OPTS = 
libraries/haskell2010_dist-install_DEP_INCLUDE_DIRS_SINGLE_QUOTED = '/home/ian/zz/ghc-7.4.2/libraries/array/include' '/home/ian/zz/ghc-7.4.2/libraries/base/include' '/home/ian/zz/ghc-7.4.2/rts/dist/build' '/home/ian/zz/ghc-7.4.2/includes' '/home/ian/zz/ghc-7.4.2/includes/dist-ghcconstants/header' '/home/ian/zz/ghc-7.4.2/includes/dist-derivedconstants/header'
libraries/haskell2010_dist-install_DEP_CC_OPTS = 
libraries/haskell2010_dist-install_DEP_LIB_DIRS_SINGLE_QUOTED = '/home/ian/zz/ghc-7.4.2/libraries/array/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/base/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/integer-gmp/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/ghc-prim/dist-install/build' '/home/ian/zz/ghc-7.4.2/rts/dist/build'
libraries/haskell2010_dist-install_DEP_EXTRA_LIBS = gmp m rt dl
libraries/haskell2010_dist-install_DEP_LD_OPTS = 
libraries/haskell2010_dist-install_BUILD_GHCI_LIB = YES

$(eval $(libraries/haskell2010_PACKAGE_MAGIC))
