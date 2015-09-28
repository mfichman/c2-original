" Vim syntax file
" Language: Apollo
" Maintainer: Matt Fichman <matt.fichman@gmail.com>
" Info: Yeeehaw!
" URL: http://stanford.edu/~mfichman
" Release Coordinator: Matt Fichman <matt.fichman@gmail.com>

syn keyword apKeyword import export struct func const for return macro enum

syn keyword apTodo contained TODO FIXME XXX

syn cluster apCommentGroup contains=apTodo
syn region apComment start="#" end="$" contains=apTodo

syn region apString start=+"+ end=+"+ 
syn region apString start=+'+ end=+'+

syn keyword apConstant true false nil

syn match apString ":\@<!:[a-zA-Z_][a-zA-Z0-9_]*"
syn match apMacro "[a-zA-Z0-9_]*!(\@="
syn match apType "\([a-zA-Z_0-9] \)\@<=[a-zA-Z_][a-zA-Z0-9_]*"
syn match apType "\() \)\@<=[a-zA-Z_][a-zA-Z0-9_]*"
syn match apFunction "\(import .*\)\@<=[a-zA-Z_][a-zA-Z0-9_]*"
syn match apFunction "\(struct \)\@<=[a-zA-Z_][a-zA-Z0-9_]*"
syn match apFunction "\(enum \)\@<=[a-zA-Z_][a-zA-Z0-9_]*"
syn match apFunction "\(func \)\@<=[a-zA-Z_][a-zA-Z0-9_]*"
syn match apFunction "\(macro \)\@<=[a-zA-Z_][a-zA-Z0-9_]*!"
syn match apConstant "[A-Z][A-Z0-9_]*[a-z]\@!"
syn match apString "[a-zA-Z0-9_]\@<!\/.*\/"

syn keyword apOperator + - / * <> == != ^ ? := > < <= >=

syn match apNumber "\<[0-9][0-9]*\>"
syn match apNumber "\<0x[0-9A-Fa-f][0-9A-Fa-f]*\>"

hi def link apKeyword Keyword
hi def link apMacro Keyword
hi def link apTodo Todo
hi def link apComment Comment
hi def link apString String
hi def link apConstant Constant
hi def link apNumber Number
hi def link apFunction Function
hi def link apType Type
hi def link apOperator Operator
hi def link apSymbol Constant
hi def link apRegex String

let b:current_syntax = "c2"

