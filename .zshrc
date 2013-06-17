PATH=$PATH:/home/guillo_e/.cabal/bin:$HOME/.bin:/bin:/sbin
export HISTFILE=~/.zsh_history
export HISTSIZE=50000
export SAVEHIST=50000
export HOSTTYPE=x86_64-linux
export PAGER=less
export TERM=xterm-256color
export RUBYOPT="rubygems"
autoload -U promptinit
autoload -U colors && colors
promptinit
setopt completealiases
autoload -U compinit
compinit
autoload -U bashcompinit
bashcompinit
zmodload zsh/complist
setopt autocd

setxkbmap us

bindkey "^[[A" history-search-backward
bindkey "^[[B" history-search-forward
bindkey "^[[1;5C" forward-word
bindkey "^[[1;5D" backward-word

alias j='jobs'
alias ls="ls --color=auto"
alias ll="ls -l --color=auto"
alias grep='grep --color=auto'
alias klog='kinit guillo_e;aklog;/usr/libexec/ns_auth;'
alias mm='make'
alias mr='make re'
alias mc='make clean'
alias ne='emacs -nw'
alias afk='zlock -immed -text "I will be back"'
alias norme='python ~/projets/test/C/test/n.py .'
alias quit='exit'
alias norme='python /bin/norme.py .'
alias cls='clean; clear'
alias ts3='~/.cabal/bin/TeamSpeak3-Client-linux_amd64/ts3client_runscript.sh&'
rapport() {google-chrome 'http://www.epitech.eu/intra/index.php?section=etudiant&page=rapport&login='$1 &}
public() {cd /u/all/$1/public}
getsvn() {svn co svn+ssh://kscm@koala-rendus.epitech.eu/$1}
alias shutdown='poweroff'
alias reload='. ~/.zshrc'

bindkey "^S" push-line
bindkey "^H" run-help

zstyle ':completion:*:processes' command 'ps -au$USER'
zstyle ':completion:*:*:kill:*:processes' list-colors "=(#b) #([0-9]#)*=36=31"

PROMPT="%B%{$fg[red]%}SeiZa%{$fg[blue]%}:%2~%b "
