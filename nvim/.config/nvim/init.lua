require "options"
require "keymaps"
require "lazy-config"
require "hop-config"

if vim.g.vscode then

    vim.cmd[[source $HOME/.config/nvim/vscode/settings.vim]]

else

    require "alpha-config"
    require "autopairs-config"
    require "bufferline-config"
    require "git-config"
    require "indentline-config"
    require "lualine-config"
    require "lsp-config"
    require "nvim-tree-config"
    require "telescope-config"
    require "toggleterm-config"
    require "treesitter-config"
    require "undotree-config"
    require "whichkey"

end


vim.cmd [[colorscheme tokyonight-night]]
