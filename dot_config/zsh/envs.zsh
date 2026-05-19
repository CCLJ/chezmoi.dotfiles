# copied from, but ommitted PATH adding and OMARCHY HOME (last 2 lines)
# source ~/.local/share/omarchy/default/bash/envs
export SUDO_EDITOR="$EDITOR"
export BAT_THEME=ansi

# Color man pages with bat
export MANROFFOPT="-c"
export MANPAGER="sh -c 'col -bx | bat -l man -p'"

# Duplicated from .config/uwsm/env so SSH works too
# export OMARCHY_PATH=$HOME/.local/share/omarchy
# export PATH=$OMARCHY_PATH/bin:$PATH:$HOME/.local/bin

