local fn = vim.fn

-- Automatically install packer
local install_path = fn.stdpath("data") .. "site/pack/packer/start/packer.nvim"
if fn.empty(fn.glob(install_path)) > 0 then
    PACKER_BOOTSTRAP = fn.system({
        "git",
        "clone",
        "--depth",
        "1",
        "https://github.com/wbthomason/packer.nvim",
        install_path,
    })
    print("Installing packer close and reopen Neovim...")
    vim.cmd([[packadd packer.nvim]])
end

-- Autocommand that reloads neovim whenever you save the plugins.lua file
-- Autocommand that Saves File Automatically
vim.cmd([[
  augroup packer_user_config
    autocmd!
    autocmd BufWritePost plugins.lua source <afile> | PackerSync
    " autocmd TextChanged,TextChangedI <buffer> silent write
  augroup end
]])

-- Use a protected call so we don't error out on first use
local status_ok, packer = pcall(require, "packer")
if not status_ok then
    return
end

-- Have packer use a popup window
packer.init({
    display = {
        open_fn = function()
            return require("packer.util").float({ border = "rounded" })
        end,
    },
})


-- Install your plugins here
return packer.startup(function(use)
    -- My plugins here

    use({ "wbthomason/packer.nvim" }) -- have packer manage itself
    use({ "windwp/nvim-autopairs" }) -- Autopairs, integrates with both cmp and treesitter


    -- Buffer Line
    use({ "moll/vim-bbye" })

    use 'tpope/vim-surround'

    -- EasyMotion for VS Code
    --use 'asvetliakov/vim-easymotion' --Alternate extension which works for same configuration.
    use 'ChristianChiarulli/vscode-easymotion'


    use { "goolord/alpha-nvim" }

    -- Comments
    use({ "numToStr/Comment.nvim" })
    use({ "JoosepAlviste/nvim-ts-context-commentstring" })

    -- Indentation
    use "lukas-reineke/indent-blankline.nvim"

    -- Colorschemes
    use "EdenEast/nightfox.nvim"

    -- cmp plugins
    use({ "hrsh7th/nvim-cmp" }) -- The completion plugin
    use({ "hrsh7th/cmp-buffer" }) -- buffer completions
    use({ "hrsh7th/cmp-path" }) -- path completions
    use({ "saadparwaiz1/cmp_luasnip" }) -- snippet completions
    use({ "hrsh7th/cmp-nvim-lsp" })
    use({ "hrsh7th/cmp-nvim-lua" })


    -- Temp
    use({ "ahmedkhalf/project.nvim" })
    use({ "lewis6991/impatient.nvim" })


    -- Vim Motions
    use 'phaazon/hop.nvim'

    -- Git
    use({ "lewis6991/gitsigns.nvim" })


    -- Status Line
    use 'tamton-aquib/staline.nvim'

    -- LSP
    use({ "neovim/nvim-lspconfig" }) -- enable LSP
    use({ "williamboman/nvim-lsp-installer" }) -- simple to use language server installer
    use({ "jose-elias-alvarez/null-ls.nvim" }) -- for formatters and linters


    -- File Explorer
    use({ "kyazdani42/nvim-tree.lua" })
    use 'kyazdani42/nvim-web-devicons'


    -- Treesitter
    use({
        "nvim-treesitter/nvim-treesitter"
    })
    use 'p00f/nvim-ts-rainbow'


    -- Telescope
    use({ "nvim-lua/plenary.nvim" }) -- Useful lua functions used by lots of plugins
    use({ "nvim-telescope/telescope.nvim" })
    use 'nvim-telescope/telescope-media-files.nvim'
    use 'nvim-lua/popup.nvim'


    -- snippets
    use({ "L3MON4D3/LuaSnip" }) --snippet engine
    use({ "rafamadriz/friendly-snippets" }) -- a bunch of snippets to use


    -- Terminal
    use({ "akinsho/toggleterm.nvim" })

    -- Which Key
    use("folke/which-key.nvim")

    -- Automatically set up your configuration after cloning packer.nvim
    -- Put this at the end after all plugins
    if PACKER_BOOTSTRAP then
        require("packer").sync()
    end
end)
