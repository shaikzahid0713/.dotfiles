lua require "keymaps"
lua require "options"
lua require "lazy-config"

if exists('g:vscode')

    source $HOME/.config/nvim/vscode/settings.vim
    source $HOME/.config/nvim/vscode/easymotion-config.vim


else

    lua require "alpha-config"
    lua require "autopairs"
    lua require "bufferline-config"
    lua require "comments-config"
    lua require "colortheme"
    lua require "nvim-tree-config"
    lua require "git-signs"
    lua require "hop-config"
    lua require "indentline-config"
    lua require "luasnip-config"
    lua require "whichkey"
    lua require "lualine-config"
    lua require "lsp-config"
    lua require "toggleterm-config"
    lua require "treesitter-config"
    lua require "telescope-config"

end

