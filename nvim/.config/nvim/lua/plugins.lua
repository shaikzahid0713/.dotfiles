return {
  "folke/which-key.nvim",
  "ChristianChiarulli/vscode-easymotion",
  "phaazon/hop.nvim",

  "kyazdani42/nvim-tree.lua",
  "kyazdani42/nvim-web-devicons",
  "akinsho/toggleterm.nvim",
  'folke/tokyonight.nvim',
  {'neovim/nvim-lspconfig'},             -- Required
  {'williamboman/mason.nvim'},           -- Optional
  {'williamboman/mason-lspconfig.nvim'}, -- Optional

  {'lewis6991/gitsigns.nvim'},

  {'tpope/vim-surround'},

  {'mbbill/undotree'},

  { "goolord/alpha-nvim" },

  -- Comments
  { "numToStr/Comment.nvim" },
  { "JoosepAlviste/nvim-ts-context-commentstring" },

  -- Indentation
  "lukas-reineke/indent-blankline.nvim",

  -- Treesitter
  {
      "nvim-treesitter/nvim-treesitter",
  },

  {
    'p00f/nvim-ts-rainbow'
  },


  -- Telescope
  { "nvim-lua/plenary.nvim" },
  { "nvim-telescope/telescope.nvim" },
  { 'nvim-telescope/telescope-media-files.nvim' },
  { 'nvim-lua/popup.nvim'},

  --  BufferLine
  {
    'akinsho/bufferline.nvim',
    dependencies = 'kyazdani42/nvim-web-devicons'
  },

  -- Snippets
  {'L3MON4D3/LuaSnip'},             -- Required

  { "windwp/nvim-autopairs" },


  -- Lualine
  {
    'nvim-lualine/lualine.nvim',
    dependencies = { 'kyazdani42/nvim-web-devicons' }
  },

    -- Lsp 
  {
    'VonHeikemen/lsp-zero.nvim',
    branch = 'v1.x',
    dependencies = {
      -- LSP Support
      {'neovim/nvim-lspconfig'},             -- Required
      {'williamboman/mason.nvim'},           -- Optional
      {'williamboman/mason-lspconfig.nvim'}, -- Optional

      -- Autocompletion
      {'hrsh7th/nvim-cmp'},         -- Required
      {'hrsh7th/cmp-nvim-lsp'},     -- Required
      {'hrsh7th/cmp-buffer'},       -- Optional
      {'hrsh7th/cmp-path'},         -- Optional
      {'saadparwaiz1/cmp_luasnip'}, -- Optional
      {'hrsh7th/cmp-nvim-lua'},     -- Optional

      -- Snippets
      {'L3MON4D3/LuaSnip'},             -- Required
    }
  }
}
