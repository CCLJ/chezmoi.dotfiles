bindkey '^I' menu-complete
bindkey '^[Z' reverse-menu-complete

# autocomplete -----------------------------
autoload -Uz up-line-or-beginning-search
autoload -Uz down-line-or-beginning-search
zle -N up-line-or-beginning-search
zle -N down-line-or-beginning-search
bindkey '^[[A' up-line-or-beginning-search
bindkey '^[[B' down-line-or-beginning-search

# autocomplete alternative
# bindkey '^[[A' history-substring-search-up
# bindkey '^[[B' history-substring-search-down
# -------------------------------------------

# Delete key was doing something weird so had to explicitly set it here
bindkey "^[[3~" delete-char
