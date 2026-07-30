%{
#include <stdio.h>
#include <stdlib.h>
#include "../ast/ast.h"

Node *root = NULL;

int yylex(void);
void yyerror(const char *s);
%}

%token INT FLOAT ID NUMBER PRINT

%%
program
    : statements
    {
        root = createNode("PROGRAM");
        printf("\nAST Root Created: %s\n", root->value);
    }
    ;
statements
    : statements statement
    | statement
    ;

statement
    : declaration ';'
    | assignment ';'
    | print_stmt ';'
    ;
declaration
    : INT ID
    {
        printf("AST Node Created: DECLARATION (int)\n");
    }
    | FLOAT ID
    {
        printf("AST Node Created: DECLARATION (float)\n");
    }
    ;

assignment
    : ID '=' NUMBER
    {
        printf("AST Node Created: ASSIGNMENT\n");
    }
    ;
print_stmt
    : PRINT '(' ID ')'
    {
        printf("AST Node Created: PRINT\n");
    }
    ;
%%

void yyerror(const char *s)
{
    printf("Syntax Error: %s\n", s);
}

int main(void)
{
    printf("Parser Started...\n");
    yyparse();
    printf("Parsing Completed.\n");
    return 0;
}
