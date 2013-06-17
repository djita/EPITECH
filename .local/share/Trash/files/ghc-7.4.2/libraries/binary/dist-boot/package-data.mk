libraries/binary_dist-boot_VERSION = 0.5.1.0
libraries/binary_dist-boot_MODULES = Data.Binary Data.Binary.Put Data.Binary.Get Data.Binary.Builder Data.Binary.Builder.Internal Data.Binary.Builder.Base
libraries/binary_dist-boot_HIDDEN_MODULES = Data.Binary.Builder.Base
libraries/binary_dist-boot_SYNOPSIS =Binary serialisation for Haskell values using lazy ByteStrings
libraries/binary_dist-boot_HS_SRC_DIRS = src
libraries/binary_dist-boot_DEPS = array-0.3.0.2 base-4.3.1.0 bytestring-0.9.1.10 containers-0.4.0.0
libraries/binary_dist-boot_DEP_NAMES = array base bytestring containers
libraries/binary_dist-boot_INCLUDE_DIRS = 
libraries/binary_dist-boot_INCLUDES = 
libraries/binary_dist-boot_INSTALL_INCLUDES = 
libraries/binary_dist-boot_EXTRA_LIBRARIES = 
libraries/binary_dist-boot_EXTRA_LIBDIRS = 
libraries/binary_dist-boot_C_SRCS  = 
libraries/binary_dist-boot_CMM_SRCS  := $(addprefix cbits/,$(notdir $(wildcard libraries/binary/cbits/*.cmm)))
libraries/binary_dist-boot_DATA_FILES = 
libraries/binary_dist-boot_HC_OPTS = -O2 -Wall -fliberate-case-threshold=1000 -XHaskell98 -XCPP -XFlexibleContexts
libraries/binary_dist-boot_CC_OPTS = 
libraries/binary_dist-boot_CPP_OPTS = -DAPPLICATIVE_IN_BASE
libraries/binary_dist-boot_LD_OPTS = 
libraries/binary_dist-boot_DEP_INCLUDE_DIRS_SINGLE_QUOTED = '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/bytestring-0.9.1.10/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/base-4.3.1.0/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/include'
libraries/binary_dist-boot_DEP_CC_OPTS = 
libraries/binary_dist-boot_DEP_LIB_DIRS_SINGLE_QUOTED = '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/containers-0.4.0.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/bytestring-0.9.1.10' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/array-0.3.0.2' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/base-4.3.1.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/integer-gmp-0.2.0.3' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/ghc-prim-0.2.0.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2'
libraries/binary_dist-boot_DEP_EXTRA_LIBS = gmp m rt dl
libraries/binary_dist-boot_DEP_LD_OPTS = 
libraries/binary_dist-boot_BUILD_GHCI_LIB = YES

$(eval $(libraries/binary_PACKAGE_MAGIC))
