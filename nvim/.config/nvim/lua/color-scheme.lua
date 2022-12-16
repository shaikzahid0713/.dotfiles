vim.cmd [[
try
  colorscheme carbonfox
catch /^Vim\%((\a\+)\)\=:E185/
  colorscheme default
  set background=dark
endtry
]]
