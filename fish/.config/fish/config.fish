source /usr/share/cachyos-fish-config/cachyos-config.fish

# overwrite greeting
# potentially disabling fastfetch
#function fish_greeting
#    # smth smth
#end
# FZF integration
set -gx FZF_DEFAULT_COMMAND "fd --type f --hidden --follow --exclude .git"
set -gx FZF_CTRL_T_COMMAND "$FZF_DEFAULT_COMMAND"
# Use bat as man pager
set -gx MANPAGER "sh -c 'col -bx | bat -l man -p'"
# Git delta (beautiful diffs)
set -gx DELTA_PAGER "less -R"
set -gx DOCKER_HOST "unix:///run/user/$(id -u)/podman/podman.sock"

# Keep COSMIC settings persistent
set -Ux XDG_CONFIG_HOME $HOME/.config
set -Ux XDG_CACHE_HOME $HOME/.cache
set -Ux XDG_DATA_HOME $HOME/.local/share

# Systemd user services aliases
alias syncthing="systemctl --user enable --now syncthing.service"
