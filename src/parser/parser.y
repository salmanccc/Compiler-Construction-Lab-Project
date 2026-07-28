%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token INT FLOAT ID NUMBER PRINT

%%

program:
      statements
    ;

statements:
      statements statement
    | statement
    ;

statement:
      declaration ';'
    | assignment ';'
    | print_stmt ';'
    ;

declaration:
      INT ID
    | FLOAT ID
    ;

assignment:
      ID '=' NUMBER
    ;

print_stmt:
      PRINT '(' ID ')'
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