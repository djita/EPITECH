ghc_stage2_VERSION = 7.4.2
ghc_stage2_MODULES = Main InteractiveUI GhciMonad GhciTags
ghc_stage2_HIDDEN_MODULES = InteractiveUI GhciMonad GhciTags
ghc_stage2_SYNOPSIS =XXX
ghc_stage2_HS_SRC_DIRS = .
ghc_stage2_DEPS = array-0.4.0.0 base-4.5.1.0 bytestring-0.9.2.1 directory-1.1.0.2 filepath-1.3.0.0 ghc-7.4.2 haskeline-0.6.4.0 mtl-1.1.1.1 process-1.1.0.1 unix-2.5.1.1
ghc_stage2_DEP_NAMES = array base bytestring directory filepath ghc haskeline mtl process unix
ghc_stage2_INCLUDE_DIRS = 
ghc_stage2_INCLUDES = 
ghc_stage2_INSTALL_INCLUDES = 
ghc_stage2_EXTRA_LIBRARIES = 
ghc_stage2_EXTRA_LIBDIRS = 
ghc_stage2_C_SRCS  = hschooks.c
ghc_stage2_CMM_SRCS  := $(addprefix cbits/,$(notdir $(wildcard ghc/cbits/*.cmm)))
ghc_stage2_DATA_FILES = settings
ghc_stage2_HC_OPTS = -fno-warn-name-shadowing -Wall -XHaskell98 -XForeignFunctionInterface -XUnboxedTuples -XFlexibleInstances -XMagicHash -XNondecreasingIndentation -XCPP -XPatternGuards
ghc_stage2_CC_OPTS = 
ghc_stage2_CPP_OPTS = -DGHCI
ghc_stage2_LD_OPTS = 
ghc_stage2_DEP_INCLUDE_DIRS_SINGLE_QUOTED = '/home/ian/zz/ghc-7.4.2/libraries/haskeline/includes' '/home/ian/zz/ghc-7.4.2/compiler/../rts/dist/build' '/home/ian/zz/ghc-7.4.2/compiler/stage2' '/home/ian/zz/ghc-7.4.2/compiler/../libraries/base/cbits' '/home/ian/zz/ghc-7.4.2/compiler/../libraries/base/include' '/home/ian/zz/ghc-7.4.2/compiler/.' '/home/ian/zz/ghc-7.4.2/compiler/parser' '/home/ian/zz/ghc-7.4.2/compiler/utils' '/home/ian/zz/ghc-7.4.2/libraries/process/include' '/home/ian/zz/ghc-7.4.2/libraries/directory/include' '/home/ian/zz/ghc-7.4.2/libraries/unix/include' '/home/ian/zz/ghc-7.4.2/libraries/bytestring/include' '/home/ian/zz/ghc-7.4.2/libraries/old-time/include' '/home/ian/zz/ghc-7.4.2/libraries/containers/include' '/home/ian/zz/ghc-7.4.2/libraries/array/include' '/home/ian/zz/ghc-7.4.2/libraries/base/include' '/home/ian/zz/ghc-7.4.2/rts/dist/build' '/home/ian/zz/ghc-7.4.2/includes' '/home/ian/zz/ghc-7.4.2/includes/dist-ghcconstants/header' '/home/ian/zz/ghc-7.4.2/includes/dist-derivedconstants/header'
ghc_stage2_DEP_CC_OPTS = 
ghc_stage2_DEP_LIB_DIRS_SINGLE_QUOTED = '/home/ian/zz/ghc-7.4.2/libraries/haskeline/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/utf8-string/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/terminfo/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/mtl/dist-install/build' '/home/ian/zz/ghc-7.4.2/compiler/stage2/build' '/home/ian/zz/ghc-7.4.2/libraries/template-haskell/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/hpc/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/hoopl/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/extensible-exceptions/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/bin-package-db/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/binary/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/Cabal/Cabal/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/process/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/pretty/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/directory/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/unix/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/bytestring/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/old-time/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/old-locale/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/filepath/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/containers/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/deepseq/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/array/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/base/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/integer-gmp/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/ghc-prim/dist-install/build' '/home/ian/zz/ghc-7.4.2/rts/dist/build'
ghc_stage2_DEP_EXTRA_LIBS = ncursesw rt util dl gmp m rt dl
ghc_stage2_DEP_LD_OPTS = 
ghc_stage2_BUILD_GHCI_LIB = YES

$(eval $(ghc_PACKAGE_MAGIC))
