vim.cmd [[
try
  colorscheme catppuccin-mocha
catch /^Vim\%((\a\+)\)\=:E185/
  colorscheme default
  set background=dark
endtry
]]
