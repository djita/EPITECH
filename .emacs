;; BOCAL STAFF 2010-2011
;; FEDORA DUMP

(toggle-scroll-bar -1)
(menu-bar-mode -1)
(tool-bar-mode -1)
(display-battery-mode)
(delete-trailing-whitespace)
(column-number-mode)
(setq load-path
      (append (list nil
		    "~/.emacs.d"
		    "~/.emacs.d/naquadah-theme"
		    "~/.emacs.d/org"
		    )
	      load-path))
(setq user-full-name "Lyoma Guillou")
(setq user-nickname "guillo_e")
(setq user-mail-adress "(guillo_e@epitech.net)")
(setq inhibit-splash-screen t)
(load "std.el")
(load "std_comment.el")
(if (file-exists-p "~/.myemacs") 
    (load-file "~/.myemacs"))
(require 'org-install)
(add-to-list 'auto-mode-alist '("\\.org\\'" . org-mode))
(normal-erase-is-backspace-mode nil)

(require 'inf-ruby)
(add-hook 'ruby-mode-hook (lambda () (local-set-key "\r" 'newline-and-indent)))
(add-hook 'ruby-mode-hook (lambda () (local-set-key "\C-c\C-r" 'ruby-send-region)))
(add-hook 'ruby-mode-hook (lambda () (local-set-key "\C-c\C-e" 'run-ruby)))
;(global-set-key "\C-c\C-s" 'run-ruby)
;(global-set-key "\C-cl" 'org-store-link)
;(global-set-key "\C-cc" 'org-capture)
;(global-set-key "\C-ca" 'org-agenda)
;(global-set-key "\C-cb" 'org-iswithb)
(transient-mark-mode 1)
(require 'naquadah-theme)
; EOF
