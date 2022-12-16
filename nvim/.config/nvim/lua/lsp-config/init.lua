local status_ok, _ = pcall(require, "lspconfig")
if not status_ok then
  return
end

require "lsp-config.configs"
require("lsp-config.handlers").setup()
require "lsp-config.null-ls"
