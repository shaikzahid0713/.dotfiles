#!/bin/bash

################################################################################
#                    CACHY OS - COMPLETE PACKAGE INSTALLER
#                    Single Consolidated Package List
#
# This script contains ALL system packages with their use cases documented.
# Run: bash packages-install.sh [--yes] [--only-pacman|--only-aur]
#
# Usage Examples:
#   bash packages-install.sh           # Interactive mode
#   bash packages-install.sh --yes     # Non-interactive (auto-confirm)
################################################################################

set -e  # Exit on error

# ════════════════════════════════════════════════════════════════════════════
#                    PACKAGE MANIFEST - ORGANIZED BY CATEGORY
# ════════════════════════════════════════════════════════════════════════════
#
# This table lists every package, its purpose, and why it's needed:
#
# ┌─────────────────────────────────────────────────────────────────────────────┐
# │ PACMAN PACKAGES (Official Arch Linux Repositories)                         │
# └─────────────────────────────────────────────────────────────────────────────┘
#
# CORE SYSTEM & BOOT:
#   base                        - Base system files
#   base-devel                  - Build tools (gcc, make, binutils)
#   linux-cachyos              - Optimized CachyOS kernel
#   linux-cachyos-headers      - Kernel headers (for modules like v4l2loopback)
#   linux-firmware             - Firmware for hardware devices
#   mkinitcpio                 - Kernel image builder for boot
#   sudo                       - Privilege escalation
#   efibootmgr                 - EFI boot entry management
#
# FILESYSTEMS:
#   dosfstools                 - FAT/VFAT filesystem support
#   e2fsprogs                  - ext4 filesystem utilities
#   exfatprogs                 - exFAT filesystem support
#   btrfs-progs                - Btrfs filesystem tools (your main filesystem)
#   btrfs-assistant            - GUI for Btrfs management
#   snapper                    - Btrfs snapshot automation
#
# NETWORKING:
#   networkmanager             - Network connection manager
#   networkmanager-openvpn     - VPN support via NM
#   iwd                        - Modern WiFi daemon
#   openssh                    - SSH client/server
#   rsync                      - File synchronization
#   wget                       - Download tool
#   curl                       - HTTP client
#   wireless-regdb             - WiFi regulatory database
#   ufw                        - Firewall management
#
# AUDIO & BLUETOOTH:
#   bluez                      - Bluetooth stack
#   bluez-libs                 - Bluetooth libraries
#   bluez-utils                - Bluetooth utilities
#   pipewire-alsa              - ALSA compatibility on PipeWire
#   pipewire-pulse             - PulseAudio compatibility on PipeWire
#   wireplumber                - Audio policy daemon
#   alsa-firmware              - Audio hardware firmware
#   alsa-plugins               - ALSA plugin support
#   alsa-utils                 - ALSA command-line tools
#   sof-firmware               - Sound Open Firmware (Intel audio)
#   pavucontrol                - PulseAudio volume control GUI
#
# DISPLAY & GPU (AMD Radeon):
#   xf86-video-amdgpu          - Modern AMDGPU driver
#   xf86-input-libinput        - Input device driver (mouse, keyboard, touch)
#   vulkan-radeon              - Vulkan GPU acceleration
#   xorg-server                - X11 server (for XWayland compatibility)
#   xorg-xinput                - X11 input configuration
#
# COSMIC DESKTOP ENVIRONMENT:
#   cosmic                     - COSMIC desktop environment
#   xdg-desktop-portal-cosmic  - Portal implementation for COSMIC
#   xdg-user-dirs              - Standard user directories
#   wofi                       - Wayland application launcher
#   qt6-wayland                - Qt6 Wayland integration
#
# FONTS:
#   noto-fonts                 - Google Noto font family
#   noto-fonts-cjk             - CJK (Chinese/Japanese/Korean) fonts
#   noto-fonts-emoji           - Emoji font support
#   ttf-cascadia-code          - Microsoft Cascadia Code (monospace)
#   ttf-dejavu                 - DejaVu font family
#   ttf-liberation             - Liberation font family
#   ttf-meslo-nerd             - Meslo Nerd Font (terminal icons)
#
# SYSTEM UTILITIES:
#   ananicy-cpp                - Auto process priority daemon (CPU/IO niceness)
#   avahi                      - mDNS/DNS-SD network discovery stack
#   fail2ban                   - Intrusion prevention (ban brute-force IPs)
#   upower                     - Power management daemon (UPS, battery info)
#   wpa_supplicant             - WPA/WPA2 WiFi authentication daemon
#   udisks2                    - Disk manager daemon (auto-mount, format)
#   btop                       - Modern system monitor (interactive)
#   duf                        - Disk usage overview
#   ripgrep                    - Fast text search (grep alternative)
#   zoxide                     - Smart directory navigation
#   stow                       - Symlink farm manager (dotfiles)
#   sd                         - String replacement (sed alternative, 15-20x faster)
#   bottom                     - System monitor with graphs (htop alternative)
#   watchexec                  - File change watcher
#   difftastic                 - Syntax-aware diff tool
#   diffutils                  - Diff utilities
#   man-db                     - Manual page database
#   man-pages                  - Manual pages collection
#   perl                       - Perl scripting language
#   python                     - Python 3 interpreter
#   python-packaging           - Python packaging utilities
#   logrotate                  - Log rotation daemon
#   reflector                  - Pacman mirror ranking tool
#   pacman-contrib             - Pacman utility scripts
#   smartmontools              - SMART monitoring for disks
#   cpupower                   - CPU frequency scaling management
#   power-profiles-daemon      - Power profile switcher
#   rtkit                      - Realtime audio priority daemon
#   lsb-release                - LSB version reporting
#   iptables-nft               - Firewall rules (nftables backend)
#
# MULTIMEDIA & CODECS:
#   ffmpegthumbnailer          - Video thumbnail generation
#   gst-libav                  - GStreamer FFmpeg plugin (codecs)
#   gst-plugin-pipewire        - GStreamer PipeWire plugin
#   gst-plugins-bad            - GStreamer extra plugins
#   gst-plugins-ugly           - GStreamer patent-restricted plugins
#   libgsf                     - ODF/Office document library
#   poppler-glib               - PDF rendering library
#   mpv                        - Modern video player (Wayland-native)
#   evince                     - PDF/document viewer
#   file-roller                - Archive manager
#
# DESKTOP APPLICATIONS:
#   chromium                   - Chromium web browser
#   firefox                    - Mozilla Firefox browser
#   wl-clipboard               - Wayland clipboard (wl-copy, wl-paste)
#
# DEVELOPMENT (Languages, Build Tools, VCS):
#   git                        - Version control system
#   cmake                      - Build system generator
#   go                         - Go programming language
#   nodejs                     - Node.js JavaScript runtime
#   npm                        - Node Package Manager
#   jdk21-openjdk              - Java 21 Development Kit
#   zed                        - GPU-accelerated modern editor (Wayland-native)
#
# CACHYOS PACKAGES:
#   cachyos-fish-config        - Pre-configured Fish shell
#   cachyos-hooks              - Pacman hooks for system maintenance
#   cachyos-kernel-manager     - Kernel version management
#   cachyos-keyring            - CachyOS signing keys
#   cachyos-mirrorlist         - CachyOS mirror list
#   cachyos-rate-mirrors       - Automatic mirror ranking
#   cachyos-settings           - System optimization settings
#   chwd                       - Hardware detection & drivers
#
# GVFS (Virtual Filesystem):
#   gvfs                       - Virtual filesystem abstraction
#   gvfs-goa                   - GNOME Online Accounts support
#   gvfs-google                - Google Drive mounting
#   gvfs-mtp                   - Android/camera media transfer
#
# CONTAINERS & VIRTUALIZATION:
#   podman                     - Rootless container runtime
#   podman-compose             - Docker Compose for Podman
#   buildah                    - Container image builder
#   distrobox                  - Seamless distro integration
#
# TERMINAL & MULTIPLEXING:
#   zellij                     - Modern terminal multiplexer (tmux alternative, Rust)
#
# MODERN CLI REPLACEMENTS (Better UX alternatives):
#   fd                         - Fast file finder (find alternative)
#   bat                        - Syntax-highlighted file display (cat alternative)
#   eza                        - Colorful directory listing (ls alternative)
#   dust                       - Disk usage analyzer (du alternative)
#   procs                      - Modern process viewer (ps alternative)
#   fzf                        - Fuzzy finder
#   jq                         - JSON CLI processor
#
# GIT ENHANCEMENTS:
#   git-delta                  - Syntax-highlighted git diffs
#   lazygit                    - Terminal UI for git
#
# DATABASE & LIBRARIES:
#   gdb                        - GNU Debugger
#   python-pip                 - Python package installer
#   python-virtualenv          - Python virtual environments
#   postgresql-libs            - PostgreSQL client libraries
#   sqlite                     - SQLite database engine
#
# PRODUCTIVITY & COLLABORATION:
#   syncthing                  - P2P file synchronization across devices
#   localsend                  - Local file transfer between nearby devices
#   obsidian                   - Markdown-based note-taking with graph view
#   sshfs                      - Mount remote folders via SSH
#   bitwarden                  - Password manager (official Electron app)
#   rclone                     - Cloud storage sync backend (S3, Drive, etc.)
#   wtype                      - Wayland keystroke simulator (Bitwarden autofill)
#   rbw                        - Unofficial Bitwarden CLI (powers Wayland autofill script)
#
# MEETINGS, REMOTE CONTROL & SCREENSHARING:
#   gnome-remote-desktop       - RDP server (Wayland support)
#   freerdp                    - RDP protocol utilities
#   xdg-desktop-portal-gtk     - GTK portal fallback
#   v4l2loopback-dkms          - Virtual camera for OBS → Zoom/Teams
#   obs-studio                 - Screen recording + virtual camera
#
# ┌─────────────────────────────────────────────────────────────────────────────┐
# │ AUR PACKAGES (Arch User Repository)                                        │
# └─────────────────────────────────────────────────────────────────────────────┘
#
#   paru                       - Rust-based AUR helper
#   visual-studio-code-bin     - VS Code (binary, not open-vsx)
#   intellij-idea-ultimate-edition - JetBrains IntelliJ IDEA
#   neovim                     - Hyperextensible Vim-based editor
#   github-cli                 - GitHub command-line interface
#   ringboard                  - Wayland clipboard manager
#   valent                     - Phone integration (GNOME Connect for COSMIC)
#
# ════════════════════════════════════════════════════════════════════════════

# Color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Helper functions
print_section() {
    echo -e "${BLUE}==== $1 ====${NC}"
}

print_success() {
    echo -e "${GREEN}✓ $1${NC}"
}

print_warn() {
    echo -e "${YELLOW}⚠ $1${NC}"
}

print_error() {
    echo -e "${RED}✗ $1${NC}"
}

confirm() {
    if [[ " $* " == *" --yes "* ]]; then
        return 0
    fi
    
    local prompt="$1"
    local response
    read -p "$prompt (Y/n): " response
    [[ "$response" != "n" && "$response" != "N" ]]
}

# ════════════════════════════════════════════════════════════════════════════
#                              PACMAN PACKAGES
# ════════════════════════════════════════════════════════════════════════════

PACMAN_PKGS=(
    # ── Base System ────────────────────────────────────────────────────────
    base base-devel linux-cachyos linux-cachyos-headers linux-firmware
    mkinitcpio sudo efibootmgr

    # ── Filesystems ────────────────────────────────────────────────────────
    dosfstools e2fsprogs exfatprogs btrfs-progs
    btrfs-assistant snapper

    # ── Networking ─────────────────────────────────────────────────────────
    networkmanager networkmanager-openvpn iwd
    openssh rsync wget curl wireless-regdb ufw

    # ── Bluetooth & Audio ───────────────────────────────────────────────────
    bluez bluez-libs bluez-utils
    pipewire-alsa pipewire-pulse wireplumber
    alsa-firmware alsa-plugins alsa-utils sof-firmware pavucontrol

    # ── Display / GPU (AMD Radeon) ──────────────────────────────────────────
    xf86-video-amdgpu xf86-input-libinput vulkan-radeon
    xorg-server xorg-xinput

    # ── COSMIC Desktop ──────────────────────────────────────────────────────
    cosmic
    xdg-desktop-portal-cosmic xdg-user-dirs
    wofi

    # ── Qt Wayland ──────────────────────────────────────────────────────────
    qt6-wayland

    # ── Fonts ───────────────────────────────────────────────────────────────
    noto-fonts noto-fonts-cjk noto-fonts-emoji
    ttf-cascadia-code ttf-dejavu ttf-liberation
    ttf-meslo-nerd

    # ── CLI / System Utilities ──────────────────────────────────────────────
    btop duf ripgrep zoxide stow sd bottom watchexec difftastic diffutils
    man-db man-pages perl python python-packaging
    logrotate reflector pacman-contrib
    smartmontools cpupower power-profiles-daemon
    rtkit lsb-release iptables-nft
    # ── System Daemons (active services) ───────────────────────────────
    ananicy-cpp                # Process priority daemon
    avahi                      # mDNS/DNS-SD network discovery
    fail2ban                   # Brute-force intrusion prevention
    upower                     # Power management daemon
    wpa_supplicant             # WiFi authentication daemon
    udisks2                    # Disk manager / auto-mount daemon
    # ── Multimedia ──────────────────────────────────────────────────────────
    ffmpegthumbnailer gst-libav gst-plugin-pipewire gst-plugins-bad
    gst-plugins-ugly libgsf poppler-glib mpv
    evince file-roller

    # ── Desktop Apps ────────────────────────────────────────────────────────
    chromium firefox wl-clipboard

    # ── Btrfs / Maintenance ────────────────────────────────────────────────
    btrfs-assistant snapper

    # ── Development ────────────────────────────────────────────────────────
    git cmake go nodejs npm jdk21-openjdk zed

    # ── CachyOS ────────────────────────────────────────────────────────────
    cachyos-fish-config cachyos-hooks cachyos-kernel-manager
    cachyos-keyring cachyos-mirrorlist
    cachyos-rate-mirrors cachyos-settings chwd

    # ── GVFS ───────────────────────────────────────────────────────────────
    gvfs gvfs-goa gvfs-google gvfs-mtp

    # ── Containers ─────────────────────────────────────────────────────────
    podman podman-compose buildah
    distrobox

    # ── Terminal Multiplexer ───────────────────────────────────────────────
    zellij

    # ── Modern CLI Replacements ────────────────────────────────────────────
    fd bat eza dust procs fzf
    jq

    # ── Git Enhancement ────────────────────────────────────────────────────
    git-delta lazygit

    # ── Development Tools ──────────────────────────────────────────────────
    gdb python-pip python-virtualenv
    postgresql-libs sqlite
    

    # ── Productivity & Collaboration ───────────────────────────────────────
    syncthing                  # P2P file sync across devices (daemon + webui)
    localsend                  # Local file transfer on same network
    obsidian                   # Markdown note-taking with bi-directional links
    sshfs                      # Mount remote SSH folders as local filesystem
    bitwarden                  # Password manager (official Electron app)
    rclone                     # Cloud sync backend used by celeste
    wtype                      # Wayland keystroke simulator (required for Bitwarden autofill)
    rbw                        # Unofficial Bitwarden CLI (Wayland autofill via wtype+wofi)
    # ── Meetings / Remote Control / Screen Sharing (Wayland) ───────────────
    gnome-remote-desktop       # RDP server (works for remote control workflows)
    freerdp                    # RDP protocol utilities
    xdg-desktop-portal-gtk     # fallback portal backend for app compatibility
    v4l2loopback-dkms          # virtual camera for OBS → Zoom/Teams
    obs-studio                 # screen recording, virtual cam for meetings
)

# ════════════════════════════════════════════════════════════════════════════
#                               AUR PACKAGES
# ════════════════════════════════════════════════════════════════════════════

AUR_PKGS=(
    # ── Core AUR Packages ──────────────────────────────────────────────────
    paru                        # AUR helper
    visual-studio-code-bin      # VS Code
    intellij-idea-ultimate-edition # IntelliJ IDEA
    neovim                      # Neovim editor
    github-cli                  # GitHub CLI
    ringboard                   # Wayland clipboard manager
    # ── Phone Integration ───────────────────────────────────────────────
    valent                      # Phone integration (KDE Connect protocol)
    # ── Media ───────────────────────────────────────────────────────────────
    qimgv-light                 # Fast Qt6 image viewer
    # ── Productivity ────────────────────────────────────────────────────────
    mindwtr-bin                 # GTD productivity system (TodoList, Mind Like Water)
)

# ════════════════════════════════════════════════════════════════════════════
#                           MAIN INSTALLATION LOGIC
# ════════════════════════════════════════════════════════════════════════════

main() {
    print_section "CachyOS - Complete Package Installer"
    
    # Parse command line arguments
    local only_pacman=false
    local only_aur=false
    local auto_yes=false
    
    for arg in "$@"; do
        case $arg in
            --only-pacman) only_pacman=true ;;
            --only-aur) only_aur=true ;;
            --yes) auto_yes=true ;;
        esac
    done
    
    # Show summary
    local pacman_count=${#PACMAN_PKGS[@]}
    local aur_count=${#AUR_PKGS[@]}
    
    echo ""
    echo "Available packages:"
    echo "  • PACMAN packages: $pacman_count"
    echo "  • AUR packages: $aur_count"
    echo "  • Total: $((pacman_count + aur_count))"
    echo ""
    
    # Install PACMAN packages
    if [[ "$only_aur" != "true" ]]; then
        if [[ "$auto_yes" == "true" ]] || confirm "Install PACMAN packages? (${pacman_count} packages)"; then
            print_section "Installing PACMAN packages..."
            sudo pacman -S --needed --noconfirm "${PACMAN_PKGS[@]}" || print_warn "Some packages may not be available"
            print_success "PACMAN packages installed"
        fi
    fi
    
    # Install AUR packages
    if [[ "$only_pacman" != "true" ]]; then
        if [[ "$auto_yes" == "true" ]] || confirm "Install AUR packages? (${aur_count} packages)"; then
            print_section "Installing AUR packages..."
            
            # Check if paru is available
            if ! command -v paru &> /dev/null; then
                print_warn "paru not found. Installing paru first..."
                sudo pacman -S --needed --noconfirm paru
            fi
            
            paru -S --needed --noconfirm "${AUR_PKGS[@]}" || print_warn "Some AUR packages may have failed"
            print_success "AUR packages installed"
        fi
    fi
    
    # ── Enable System Services ─────────────────────────────────────────
    print_section "Enabling system services..."

    # System-level services (require sudo)
    local system_services=(
        NetworkManager
        bluetooth
        power-profiles-daemon
        avahi-daemon
        fail2ban
        ufw
        udisks2
        systemd-timesyncd
        wpa_supplicant
        ananicy-cpp
    )
    for svc in "${system_services[@]}"; do
        sudo systemctl enable --now "$svc" 2>/dev/null && print_success "Enabled: $svc" || print_warn "Could not enable: $svc (may not be installed)"
    done

    # User-level services (no sudo)
    local user_services=(
        syncthing
        pipewire
        wireplumber
        pipewire-pulse
        ringboard-server
        ringboard-wayland
    )
    for svc in "${user_services[@]}"; do
        systemctl --user enable --now "$svc" 2>/dev/null && print_success "Enabled (user): $svc" || print_warn "Could not enable (user): $svc"
    done

    # ── Post-Installation / State Replication ──────────────────────────
    print_section "Replicating User State and Configurations..."
    
    # 1. Set qimgv as default image viewer
    if command -v xdg-mime &> /dev/null; then
        xdg-mime default qimgv.desktop image/jpeg image/png image/gif image/webp image/tiff image/bmp image/x-icon image/svg+xml && print_success "Set qimgv as default image viewer"
    fi

    # 2. Setup Dotfiles (if not exist)
    if [ ! -d "$HOME/.dotfiles" ]; then
        print_warn "Dotfiles repository not found at ~/.dotfiles!"
        print_warn "To fully replicate state on a new laptop, you must clone your dotfiles repository."
        print_warn "Example: git clone git@github.com:shaikzahid0713/.dotfiles.git ~/.dotfiles"
    else
        # Stow directories
        print_success "Dotfiles repository found. Stowing configurations..."
        cd "$HOME/.dotfiles"
        stow cosmic fish git scripts systemd wofi zsh
        
        # Enable the ringboard cleanup timer we created
        systemctl --user daemon-reload
        systemctl --user enable --now ringboard-cleanup.timer 2>/dev/null && print_success "Enabled (user timer): ringboard-cleanup.timer"
    fi

    # 3. Change default shell to fish
    if [ "$SHELL" != "/usr/bin/fish" ] && command -v fish &> /dev/null; then
        print_section "Changing default shell to fish..."
        chsh -s $(command -v fish)
    fi

    print_section "Installation Complete"
    print_success "System is matching your expected state!"
    echo ""
    echo "Actions & Steps to perfectly replicate on another laptop:"
    echo "  1. Generate SSH Keys: ssh-keygen -t ed25519 -C \"shaikhzahid0713@gmail.com\""
    echo "  2. Add SSH Key to GitHub: xclip -sel clip < ~/.ssh/id_ed25519.pub"
    echo "  3. Clone Dotfiles: git clone git@github.com:shaikzahid0713/.dotfiles.git ~/.dotfiles"
    echo "  4. Setup Bitwarden Wayland script: Login to rbw (rbw login) and sync (rbw sync)"
    echo "  5. Start using your perfectly replicated COSMIC system!"
    echo ""
}

# ════════════════════════════════════════════════════════════════════════════

# Check if running as root for sudo operations
if [[ $EUID -eq 0 ]]; then
    print_error "Do not run this script as root. It uses sudo internally."
    exit 1
fi

# Run main function with all arguments
main "$@"
