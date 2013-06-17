;;
;; div.el for emacs conf in site-local
;; 
;; Made by Nicolas Sadirac
;; Login   <rn@epita.fr>
;; 
;; Started on  Sun Oct 17 02:20:57 1993 Nicolas Sadirac
;; Last update Sat Feb 23 13:27:05 2013 Lyoma Guillou
;;

(defun do_insert_time () 
  (interactive)
 (insert-string (current-time-string)))
(set-variable 'c-argdecl-indent   0)

(normal-erase-is-backspace-mode nil)

(global-set-key "" 'backward-delete-char)
(global-set-key "c" 'compile)
(global-set-key "" 'goto-line)
