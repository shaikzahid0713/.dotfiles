local opts = { noremap = true, silent = true }

local term_opts = { silent = true }

-- Shorten function name
local keymap = vim.api.nvim_set_keymap

--Remap space as leader key
keymap("", "<Space>", "<Nop>", opts)
vim.g.mapleader = " "
vim.g.maplocalleader = " "

-- Modes
--   normal_mode = "n",
--   insert_mode = "i",
--   visual_mode = "v",
--   visual_block_mode = "x",
--   term_mode = "t",
--   command_mode = "c",

--VS Code 
if vim.g.vscode then

    keymap("n", "<Tab>", " :Tabnext<CR>", opts)
    keymap("n", "<S-Tab>", " :Tabprev<CR>", opts)

else
        -- Normal --
    -- Better window navigation
    keymap("n", "<C-h>", "<C-w>h", opts)
    keymap("n", "<C-k>", "<C-w>k", opts)
    keymap("n", "<C-j>", "<C-w>j", opts)
    keymap("n", "<C-l>", "<C-w>l", opts)

    -- Resize with arrows
    keymap("n", "<C-Up>", ":resize -2<CR>", opts)
    keymap("n", "<c-down>", ":resize +2<cr>", opts)
    keymap("n", "<c-right>", ":vertical resize -2<cr>", opts)
    keymap("n", "<c-left>", ":vertical resize +2<cr>", opts)

    -- Navigation
    keymap("n", "z", "0", opts) --Start of Line
    keymap("n", ",", "$", opts) -- End of Line
    keymap("n", ";", "%", opts) -- Move between Braces {}()[]

    --Copy whole file
    keymap("n", "yya", "ggyG", opts)
    keymap("n", "dda", "ggdG", opts)

    --Delete 
    keymap("i", "<C-backspace>", "<Esc>dbxi", opts)

    -- navigate buffers
    keymap("n", "<tab>", ":bnext<cr>", opts)
    keymap("n", "<s-tab>", ":bprevious<cr>", opts)
    keymap("n", "<leader>so", ":BufferLineSortByExtension<cr>", opts)

    -- move text up and down
    keymap("n", "<a-j>", "<esc>:m .+1<cr>==gi", opts)
    keymap("n", "<a-k>", "<esc>:m .-2<cr>==gi", opts)

    -- insert --
    -- press jk fast to exit insert mode 
    keymap("i", "jk", "<esc>", opts)
    keymap("i", "kj", "<esc>", opts)

    -- press jj fast to move cursor backword
    keymap("i", "jj", "<esc>i", opts)
    keymap("i", "kk", "<esc>la", opts)
    keymap("i", "ll", "<esc>o", opts)
    keymap("i", "hh", "<esc>O", opts)
    keymap("i", "//", "<esc>g", opts)

    -- visual --
    -- stay in indent mode
    keymap("v", "<", "<gv", opts)
    keymap("v", ">", ">gv", opts)

    -- move text up and down
    keymap("v", "<a-j>", ":m .+1<cr>==", opts)
    keymap("v", "<a-k>", ":m .-2<cr>==", opts)
    keymap("v", "p", '"_dp', opts)

    -- Visual Block --
    -- Move text up and down
    keymap("x", "J", ":move '>+1<CR>gv-gv", opts)
    keymap("x", "K", ":move '<-2<CR>gv-gv", opts)
    keymap("x", "<A-j>", ":move '>+1<CR>gv-gv", opts)
    keymap("x", "<A-k>", ":move '<-2<CR>gv-gv", opts)

     --Terminal --
     --Better terminal navigation
     keymap("t", "<C-h>", "<C-\\><C-N><C-w>h", term_opts)
     keymap("t", "<C-j>", "<C-\\><C-N><C-w>j", term_opts)
     keymap("t", "<C-k>", "<C-\\><C-N><C-w>k", term_opts)
     keymap("t", "<C-l>", "<C-\\><C-N><C-w>l", term_opts)


end




