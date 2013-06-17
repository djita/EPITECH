libraries/hpc_dist-boot_VERSION = 0.5.1.1
libraries/hpc_dist-boot_MODULES = Trace.Hpc.Util Trace.Hpc.Mix Trace.Hpc.Tix Trace.Hpc.Reflect
libraries/hpc_dist-boot_HIDDEN_MODULES = 
libraries/hpc_dist-boot_SYNOPSIS =Code Coverage Library for Haskell
libraries/hpc_dist-boot_HS_SRC_DIRS = .
libraries/hpc_dist-boot_DEPS = base-4.3.1.0 containers-0.4.0.0 directory-1.1.0.0 old-time-1.0.0.6
libraries/hpc_dist-boot_DEP_NAMES = base containers directory old-time
libraries/hpc_dist-boot_INCLUDE_DIRS = 
libraries/hpc_dist-boot_INCLUDES = 
libraries/hpc_dist-boot_INSTALL_INCLUDES = 
libraries/hpc_dist-boot_EXTRA_LIBRARIES = 
libraries/hpc_dist-boot_EXTRA_LIBDIRS = 
libraries/hpc_dist-boot_C_SRCS  = 
libraries/hpc_dist-boot_CMM_SRCS  := $(addprefix cbits/,$(notdir $(wildcard libraries/hpc/cbits/*.cmm)))
libraries/hpc_dist-boot_DATA_FILES = 
libraries/hpc_dist-boot_HC_OPTS = -Wall -XHaskell98 -XCPP
libraries/hpc_dist-boot_CC_OPTS = 
libraries/hpc_dist-boot_CPP_OPTS = 
libraries/hpc_dist-boot_LD_OPTS = 
libraries/hpc_dist-boot_DEP_INCLUDE_DIRS_SINGLE_QUOTED = '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/directory-1.1.0.0/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/unix-2.4.2.0/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/old-time-1.0.0.6/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/base-4.3.1.0/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/include' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/include'
libraries/hpc_dist-boot_DEP_CC_OPTS = 
libraries/hpc_dist-boot_DEP_LIB_DIRS_SINGLE_QUOTED = '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/directory-1.1.0.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/unix-2.4.2.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/old-time-1.0.0.6' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/old-locale-1.0.0.2' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/filepath-1.2.0.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/containers-0.4.0.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/array-0.3.0.2' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/base-4.3.1.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/integer-gmp-0.2.0.3' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2/ghc-prim-0.2.0.0' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2' '/home/ian/bindists/7.0.2/inst/lib/ghc-7.0.2'
libraries/hpc_dist-boot_DEP_EXTRA_LIBS = rt util dl gmp m rt dl
libraries/hpc_dist-boot_DEP_LD_OPTS = 
libraries/hpc_dist-boot_BUILD_GHCI_LIB = YES

$(eval $(libraries/hpc_PACKAGE_MAGIC))
