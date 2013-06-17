libraries/xhtml_dist-install_VERSION = 3000.2.0.4
libraries/xhtml_dist-install_MODULES = Text.XHtml Text.XHtml.Frameset Text.XHtml.Strict Text.XHtml.Transitional Text.XHtml.Debug Text.XHtml.Table Text.XHtml.Strict.Attributes Text.XHtml.Strict.Elements Text.XHtml.Frameset.Attributes Text.XHtml.Frameset.Elements Text.XHtml.Transitional.Attributes Text.XHtml.Transitional.Elements Text.XHtml.BlockTable Text.XHtml.Extras Text.XHtml.Internals
libraries/xhtml_dist-install_HIDDEN_MODULES = Text.XHtml.Strict.Attributes Text.XHtml.Strict.Elements Text.XHtml.Frameset.Attributes Text.XHtml.Frameset.Elements Text.XHtml.Transitional.Attributes Text.XHtml.Transitional.Elements Text.XHtml.BlockTable Text.XHtml.Extras Text.XHtml.Internals
libraries/xhtml_dist-install_SYNOPSIS =An XHTML combinator library
libraries/xhtml_dist-install_HS_SRC_DIRS = .
libraries/xhtml_dist-install_DEPS = base-4.5.1.0
libraries/xhtml_dist-install_DEP_NAMES = base
libraries/xhtml_dist-install_INCLUDE_DIRS = 
libraries/xhtml_dist-install_INCLUDES = 
libraries/xhtml_dist-install_INSTALL_INCLUDES = 
libraries/xhtml_dist-install_EXTRA_LIBRARIES = 
libraries/xhtml_dist-install_EXTRA_LIBDIRS = 
libraries/xhtml_dist-install_C_SRCS  = 
libraries/xhtml_dist-install_CMM_SRCS  := $(addprefix cbits/,$(notdir $(wildcard libraries/xhtml/cbits/*.cmm)))
libraries/xhtml_dist-install_DATA_FILES = 
libraries/xhtml_dist-install_HC_OPTS = -Wall -XHaskell98 -XCPP
libraries/xhtml_dist-install_CC_OPTS = 
libraries/xhtml_dist-install_CPP_OPTS = 
libraries/xhtml_dist-install_LD_OPTS = 
libraries/xhtml_dist-install_DEP_INCLUDE_DIRS_SINGLE_QUOTED = '/home/ian/zz/ghc-7.4.2/libraries/base/include' '/home/ian/zz/ghc-7.4.2/rts/dist/build' '/home/ian/zz/ghc-7.4.2/includes' '/home/ian/zz/ghc-7.4.2/includes/dist-ghcconstants/header' '/home/ian/zz/ghc-7.4.2/includes/dist-derivedconstants/header'
libraries/xhtml_dist-install_DEP_CC_OPTS = 
libraries/xhtml_dist-install_DEP_LIB_DIRS_SINGLE_QUOTED = '/home/ian/zz/ghc-7.4.2/libraries/base/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/integer-gmp/dist-install/build' '/home/ian/zz/ghc-7.4.2/libraries/ghc-prim/dist-install/build' '/home/ian/zz/ghc-7.4.2/rts/dist/build'
libraries/xhtml_dist-install_DEP_EXTRA_LIBS = gmp m rt dl
libraries/xhtml_dist-install_DEP_LD_OPTS = 
libraries/xhtml_dist-install_BUILD_GHCI_LIB = YES

$(eval $(libraries/xhtml_PACKAGE_MAGIC))
