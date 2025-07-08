# dotfiles

Before initializing dotfiles with chezmoi make sure to do the following:
- Setup zsh as shell
- Setup oh-my-zsh
- Install nerdfont Iosevka (either manually or using pacman/yay which I prefer, and then setup the config in your terminal emulator)
    - To setup the font for kitty, edit `~/.config/kitty/kitty.conf` (or press CTRL+SHIFT+F2) and make sure to have:
    ```
    # BEGIN_KITTY_FONTS
    font_family      family="Iosevka"
    bold_font        auto
    italic_font      auto
    bold_italic_font auto
    # END_KITTY_FONTS
    ```

There is a script that will install the following packages automatically in arch, assuming yay is installed
- curl
- wget
- fzf
- ripgrep
- bat
- eza
- btop
- tmux
- yazi
- zoxide
- neovim
- ffmpeg

Other utilites to install manually:
- volta (node manager) `https://volta.sh/`
```sh
curl https://get.volta.sh | bash
volta install node
```

- hyprland with waybar (check current documentation for this https://github.com/hyprwm/Hyprland)
- qmk `https://qmk.fm/`
- docker (make sure to install the engines and not the desktop app)

