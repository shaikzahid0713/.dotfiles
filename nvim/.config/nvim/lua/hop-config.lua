local hop = require'hop'
hop.setup { keys = "etovxqpdygfblzhckisuran" }

-- assign hop word highlight to the letter f in all vim modes
vim.keymap.set('', 'f', function()
  hop.hint_char1()
end, { remap=true })
