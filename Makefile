CC = gcc
FLEX = flex
BISON = bison

all:
	@echo "Building Compiler Project..."
	@echo "Done."

clean:
	rm -f src/lexer/lexer
	rm -f src/parser/parser
	rm -f src/semantic/semantic
	rm -f src/ast/ast
	rm -f src/symbol_table/symbol_table
	rm -f src/tac/tac
	rm -f src/parser/parser.tab.c
	rm -f src/parser/parser.tab.h
	rm -f src/parser/lex.yy.c
