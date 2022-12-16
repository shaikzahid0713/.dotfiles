require'staline'.setup{
	sections = {
		left = {
			'- ', '-mode', 'left_sep_double',
			'file_name', '  ', 'branch'
		},
		mid  = {'lsp'},
		right= {
			'cool_symbol', '  ',
			vim.bo.fileencoding:upper(), 'right_sep_double', '-line_column'
		}
	},
	defaults = {
		cool_symbol = "  ",
		left_separator = "",
		right_separator = "",
		bg = "#100720",
		full_path = false,
		branch_symbol = " "
	},
	mode_colors = {
		n = "#8FE3CF",
		i = "#F9CEEE",
		ic= "#FB2576",
		c = "#748DA6",
        v = "#FFF7AE"
	}
}
