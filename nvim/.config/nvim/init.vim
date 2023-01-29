lua require "options" 
lua require "whichkey" 
lua require "plugins" 
lua require "keymaps" 

if exists('g:vscode')

	source $HOME/.config/nvim/vscode/settings.vim
	source $HOME/.config/nvim/vscode/easymotion-config.vim
  
else 
	
    lua require "lsp-config" 
    lua require "alpha-config" 
    lua require "autopairs" 
    lua require "cmp-autocomplete" 
    lua require "color-scheme" 
    lua require "comments-config" 
    lua require "gitsigns-config" 
    lua require "hop-config" 
    lua require "impatient-config" 
    lua require "indentline-config" 
    lua require "staline-config" 
    lua require "stabline-config" 
    lua require "luasnip-config" 
    lua require "nvim-tree-config" 
    lua require "telescope-config" 
    lua require "toggleterm-config" 
    lua require "treesitter-config" 
	
endif
