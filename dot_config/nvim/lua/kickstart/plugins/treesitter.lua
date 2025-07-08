return {
  { -- Highlight, edit, and navigate code
    'nvim-treesitter/nvim-treesitter',
    lazy = false,
    branch = 'main',
    build = ':TSUpdate',
    opts = {},
    -- main = 'nvim-treesitter.configs', -- Sets main module to use for opts
    -- [[ Configure Treesitter ]] See `:help nvim-treesitter`
    config = function(_, opts)
      require('nvim-treesitter').setup(opts)
      local ensureInstalled =
        { 'bash', 'c', 'diff', 'html', 'lua', 'luadoc', 'markdown', 'markdown_inline', 'query', 'vim', 'vimdoc', 'go', 'rust', 'elixir', 'toml', 'yaml' }
      local alreadyInstalled = require('nvim-treesitter').get_installed 'parsers'
      local parsersToInstall = vim
        .iter(ensureInstalled)
        :filter(function(parser)
          return not vim.tbl_contains(alreadyInstalled, parser)
        end)
        :totable()
      print(parsersToInstall)
      if #parsersToInstall > 0 then
        require('nvim-treesitter').install(parsersToInstall)
      end

      local parsersInstalled = require('nvim-treesitter').get_installed 'parsers'
      for _, parser in pairs(parsersInstalled) do
        local filetypes = vim.treesitter.language.get_filetypes(parser)
        vim.api.nvim_create_autocmd({ 'FileType' }, {
          group = vim.api.nvim_create_augroup('EnableTreesitterHighlighting', { clear = true }),
          pattern = filetypes,
          callback = function(event)
            print(event.buf)
            local parser_installed = pcall(vim.treesitter.get_parser, event.buf, parser)
            if parser_installed then
              pcall(vim.treesitter.start, event.buf, parser)
            end
          end,
        })
      end
    end,
    -- There are additional nvim-treesitter modules that you can use to interact
    -- with nvim-treesitter. You should go explore a few and see what interests you:
    --
    --    - Incremental selection: Included, see `:help nvim-treesitter-incremental-selection-mod`
    --    - Show your current context: https://github.com/nvim-treesitter/nvim-treesitter-context
  },
  {
    'nvim-treesitter/nvim-treesitter-textobjects',
    opts = {},
    branch = 'main',
    config = function()
      require('nvim-treesitter-textobjects').setup {
        textobjects = {
          select = {
            enable = true,
            -- Automatically jump forward to textobj, similar to targets.vim
            lookahead = true,
            keymaps = {
              -- You can use the capture groups defined in textobjects.scm
              ['af'] = { query = '@function.outer', desc = 'Select outer function region' },
              ['if'] = { query = '@function.inner', desc = 'Select inner function region' },
              ['ac'] = { query = '@class.outer', desc = 'Select outer class region' },
              -- You can optionally set descriptions to the mappings (used in the desc parameter of
              -- nvim_buf_set_keymap) which plugins like which-key display
              ['ic'] = { query = '@class.inner', desc = 'Select inner class region' },
              -- You can also use captures from other query groups like `locals.scm`
              ['as'] = { query = '@local.scope', query_group = 'locals', desc = 'Select language scope' },
            },
          },
        },
      }
    end,
  },
}
-- vim: ts=2 sts=2 sw=2 et
