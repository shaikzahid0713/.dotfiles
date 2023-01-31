require'hop'.setup { keys = 'etovxqpdygfblzhckisuran', term_seq_bias = 0.5 }

vim.api.nvim_set_keymap('', 'f', "<cmd>lua require'hop'.hint_char1()<cr>", {})
vim.api.nvim_set_keymap("n", 't', "<cmd>HopPattern<CR>", {noremap=true})

