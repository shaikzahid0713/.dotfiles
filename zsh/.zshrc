# If you come from bash you might have to change your $PATH.

# Path to your oh-my-zsh installation.

export ZSH="$HOME/.oh-my-zsh"
export PATH=$HOME/bin:/usr/local/bin:$PATH
export PATH=$HOME/node/bin/:$PATH
export PATH="$HOME/.local/bin:$PATH"

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time oh-my-zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/ohmyzsh/ohmyzsh/wiki/Themes
ZSH_THEME="agnoster"

# Set list of themes to pick from when loading at random
# Setting this variable when ZSH_THEME=random will cause zsh to load
# a theme from this variable instead of looking in $ZSH/themes/
# If set to an empty array, this variable will have no effect.
# ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell" "agnoster" )

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment one of the following lines to change the auto-update behavior
# zstyle ':omz:update' mode disabled  # disable automatic updates
# zstyle ':omz:update' mode auto      # update automatically without asking
# zstyle ':omz:update' mode reminder  # just remind me to update when it's time

# Uncomment the following line to change how often to auto-update (in days).
# zstyle ':omz:update' frequency 13

# Uncomment the following line if pasting URLs and other text is messed up.
# DISABLE_MAGIC_FUNCTIONS="true"

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# You can also set it to another string to have that shown instead of the default red dots.
# e.g. COMPLETION_WAITING_DOTS="%F{yellow}waiting...%f"
# Caution: this setting can cause issues with multiline prompts in zsh < 5.7.1 (see #5765)
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# You can set one of the optional three formats:
# "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# or set a custom format using the strftime function format specifications,
# see 'man strftime' for details.
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load?
# Standard plugins can be found in $ZSH/plugins/
# Custom plugins may be added to $ZSH_CUSTOM/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(
    git
    vi-mode
)

# Reference - 
# Youtube - https://www.youtube.com/watch?v=eLEo4OQ-cuQ
# vimrc - https://gist.github.com/LukeSmithxyz/e62f26e55ea8b0ed41a65912fbebbe52
# vi mode


bindkey -v
export KEYTIMEOUT=20

VI_MODE_SET_CURSOR=true


# Change cursor shape for different vi modes.

function zle-keymap-select {
  if [[ ${KEYMAP} == vicmd ]] ||
     [[ $1 = 'block' ]]; then
    echo -ne '\e[1 q'
  elif [[ ${KEYMAP} == main ]] ||
       [[ ${KEYMAP} == viins ]] ||
       [[ ${KEYMAP} = '' ]] ||
       [[ $1 = 'beam' ]]; then
    echo -ne '\e[5 q'
  fi
}


typeset -ga POWERLEVEL9K_LEFT_PROMPT_ELEMENTS=(
    vi_mode
    dir
    vcs
    newline
    prompt_char
)
typeset -g POWERLEVEL9K_MODE=nerdfont-complete
typeset -g POWERLEVEL9K_PROMPT_ADD_NEWLINE=true
typeset -g POWERLEVEL9K_VI_INSERT_MODE_STRING='  INSERT'
typeset -g POWERLEVEL9K_VI_MODE_INSERT_FOREGROUND=11
typeset -g POWERLEVEL9K_VI_COMMAND_MODE_STRING='  NORMAL'
typeset -g POWERLEVEL9K_VI_MODE_NORMAL_FOREGROUND=10
typeset -g POWERLEVEL9K_VI_VISUAL_MODE_STRING='  VISUAL'
typeset -g POWERLEVEL9K_VI_MODE_VISUAL_FOREGROUND=12
typeset -g POWERLEVEL9K_VI_OVERWRITE_MODE_STRING='  REPLACE'
typeset -g POWERLEVEL9K_VI_MODE_OVERWRITE_FOREGROUND=9
typeset -g POWERLEVEL9K_PROMPT_CHAR_OVERWRITE_STATE=true
typeset -g POWERLEVEL9K_PROMPT_CHAR_BACKGROUND=
typeset -g POWERLEVEL9K_PROMPT_CHAR_{OK,ERROR}_VIINS_FOREGROUND=11
typeset -g POWERLEVEL9K_PROMPT_CHAR_{OK,ERROR}_VICMD_FOREGROUND=10
typeset -g POWERLEVEL9K_PROMPT_CHAR_{OK,ERROR}_VIVIS_FOREGROUND=12
typeset -g POWERLEVEL9K_PROMPT_CHAR_{OK,ERROR}_VIOWR_FOREGROUND=9
typeset -g POWERLEVEL9K_PROMPT_CHAR_{OK,ERROR}_{VIINS,VICMD,VIVIS,VIOWR}_CONTENT_EXPANSION=' ☰ '




source $ZSH/oh-my-zsh.sh
source ~/Git/zsh-autocomplete/zsh-autocomplete.plugin.zsh



# Use lf to switch directories and bind it to ctrl-o
lfcd () {
    tmp="$(mktemp)"
    lf -last-dir-path="$tmp" "$@"
    if [ -f "$tmp" ]; then
        dir="$(cat "$tmp")"
        rm -f "$tmp"
        [ -d "$dir" ] && [ "$dir" != "$(pwd)" ] && cd "$dir"
    fi
}
bindkey -s '^o' 'lfcd\n'


# User configuration

# export MANPATH="/usr/local/man:$MANPATH"

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='mvim'
# fi

# Compilation flags
# export ARCHFLAGS="-arch x86_64"

# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"

alias e="exit"
alias c="clear"
alias b="brillo"
alias v="codium" 
alias su="sudo su"
alias bu="sudo brillo -A"
alias bd="sudo brillo -U"
alias remove="sudo rm -rf"
alias cp="cd ~/.config/nvim/Contests/"
alias config="cd ~/.config/nvim/"
alias desktop="cd ~/Desktop/"
alias g++="g++ -std=c++17"
alias zsh="nvim ~/.zshrc"
alias init="nvim ~/.config/nvim/init.vim"
alias kit="nvim ~/.config/kitty/kitty.conf"
alias sts="nvim ~/.vrapperrc"
alias idea="nvim ~/.ideavimrc"
alias linux="nvim ~/linux.sh"

# if [ -e /home/shaik/.nix-profile/etc/profile.d/nix.sh ]; then . /home/shaik/.nix-profile/etc/profile.d/nix.sh; fi # added by Nix installer
