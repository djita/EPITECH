utils/haddock_dist_VERSION = 2.11.0
utils/haddock_dist_MODULES = Main Haddock.Interface Haddock.Interface.Rename Haddock.Interface.Create Haddock.Interface.AttachInstances Haddock.Interface.LexParseRn Haddock.Interface.ParseModuleHeader Haddock.Lex Haddock.Parse Haddock.Utils Haddock.Backends.Xhtml Haddock.Backends.Xhtml.Decl Haddock.Backends.Xhtml.DocMarkup Haddock.Backends.Xhtml.Layout Haddock.Backends.Xhtml.Names Haddock.Backends.Xhtml.Themes Haddock.Backends.Xhtml.Types Haddock.Backends.Xhtml.Utils Haddock.Backends.LaTeX Haddock.Backends.HaddockDB Haddock.Backends.Hoogle Haddock.ModuleTree Haddock.Types Haddock.Doc Haddock.Version Haddock.InterfaceFile Haddock.Options Haddock.GhcUtils Haddock.Convert
utils/haddock_dist_HIDDEN_MODULES = Haddock.Interface Haddock.Interface.Rename Haddock.Interface.Create Haddock.Interface.AttachInstances Haddock.Interface.LexParseRn Haddock.Interface.ParseModuleHeader Haddock.Lex Haddock.Parse Haddock.Utils Haddock.Backends.Xhtml Haddock.Backends.Xhtml.Decl Haddock.Backends.Xhtml.DocMarkup Haddock.Backends.Xhtml.Layout Haddock.Backends.Xhtml.Names Haddock.Backends.Xhtml.Themes Haddock.Backends.Xhtml.Types Haddock.Backends.Xhtml.Utils Haddock.Backends.LaTeX Haddock.Backends.HaddockDB Haddock.Backends.Hoogle Haddock.ModuleTree Haddock.Types Haddock.Doc Haddock.Version Haddock.InterfaceFile Haddock.Options Haddock.GhcUtils Haddock.Convert
utils/haddock_dist_SYNOPSIS =A documentation-generation tool for Haskell libraries
utils/haddock_dist_HS_SRC_DIRS = src
utils/haddock_dist_DEPS = Cabal-1.14.0 array-0.4.0.0 base-4.5.1.0 containers-0.4.2.1 directory-1.1.0.2 filepath-1.3.0.0 ghc-7.4.2 pretty-1.1.1.0 xhtml-3000.2.0.4
utils/haddock_dist_DEP_NAMES = Cabal array base containers directory filepath ghc pretty xhtml
utils/haddock_dist_INCLUDE_DIRS = 
utils/haddock_dist_INCLUDES = 
utils/haddock_dist_INSTALL_INCLUDES = 
utils/haddock_dist_EXTRA_LIBRARIES = 
utils/haddock_dist_EXTRA_LIBDIRS = 
utils/haddock_dist_C_SRCS  = 
utils/haddock_dist_CMM_SRCS  := $(addprefix cbits/,$(notdir $(wildcard utils/haddock/cbits/*.cmm)))
utils/haddock_dist_DATA_FILES = html/frames.html html/haddock-util.js html/Classic.theme/haskell_icon.gif html/Classic.theme/minus.gif html/Classic.theme/plus.gif html/Classic.theme/xhaddock.css html/Ocean.std-theme/hslogo-16.png html/Ocean.std-theme/minus.gif html/Ocean.std-theme/ocean.css html/Ocean.std-theme/plus.gif html/Ocean.std-theme/synopsis.png latex/haddock.sty
utils/haddock_dist_HC_OPTS = -funbox-strict-fields -O2 -Wall -fwarn-tabs -XHaskell2010 -XCPP -XDeriveDataTypeable -XScopedTypeVariables -XMagicHash
utils/haddock_dist_CC_OPTS = 
utils/haddock_dist_CPP_OPTS = -DIN_GHC_TREE
utils/haddock_dist_LD_OPTS = 
utils/haddock_dist_DEP_INCLUDE_DIRS_SINGLE_QUOTED = '/home/ian/zz/ghc-7.4.2/compiler/../rts/dist/build' '/home/ian/zz/ghc-7.4.2/compiler/stage2' '/home/ian/zz/ghc-7.4.2/compiler/../libraries/base/cbits' '/home/ian/zz/ghc-7.4.2/compiler/../libraries/base/include' '/home/ian/zz/ghc-7.4.2/compiler/.' '/home/ian/zz/ghc-7.4.2/compiler/parser' '/home/ian/zz/ghc-7.4.2/compiler/utils' '/home/ian/zz/ghc-7.4.2/libraries/process/include' '/home/ian/zz/ghc-7.4.2/libraries/directory/include' '/home/ian/zz/ghc-7.4.2/libraries/unix/include' '/home/ian/zz/ghc-7.4.2/libraries/bytestring/include' '/home/ian/zz/ghc-7.4.2/libraries/old-time/include' '/home/ian/zz/ghc-7.4.2/libraries/containers/include' '/home/ian/zz/ghc-7.4.2/libraries/array/include' '/home/ian/zz/ghc-7.4.2/libraries/base/include' '/home/ian/zz/ghc-7.4.2/rts/dist/build' '/home/ian/zz/ghc-7.4.2/includes' '/home/ian/zz/ghc-7.4.2/includes/dist-ghcconstants/header' '/home/ian/zz/ghc-7.4.2/includes/dist-derivedconstants/header'
utils/haddock_dist_DEP_CC_OPTS = 
utils/haddock_dist_DEP_LIB_DIRS_SINGLE_QUOTED = '/home/ian/zz/ghc-7.4.2/libraries/xhtml/dist-install/build' '/home/ian/zz/ghc-7.4.2/compiler/stage2/build' '/home/ian/zz/ghc-7.4.2/libraries/template-haskell/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/hpc/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/hoopl/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/bin-package-db/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/binary/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/Cabal/Cabal/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/process/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/pretty/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/directory/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/unix/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/bytestring/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/old-time/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/old-locale/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/filepath/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/containers/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/deepseq/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/array/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/base/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/integer-gmp/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/ghc-prim/dist-install/build' '/home/ian/zz/ghc-7.4.2/rts/dist/build'
utils/haddock_dist_DEP_EXTRA_LIBS = rt util dl gmp m rt dl
utils/haddock_dist_DEP_LD_OPTS = 
utils/haddock_dist_BUILD_GHCI_LIB = YES

$(eval $(utils/haddock_PACKAGE_MAGIC))
