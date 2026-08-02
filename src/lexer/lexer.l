
%{
#include <stdio.h>
%}

LETTER      [a-zA-Z_]
DIGIT       [0-9]
ID          {LETTER}({LETTER}|{DIGIT})*
INT         {DIGIT}+
FLOAT       {DIGIT}+"."{DIGIT}+

%%

"int"|"float"|"char"|"if"|"else"|"while"|"return"|"print" {
    printf("KEYWORD : %s\n", yytext);
}

{FLOAT} {
    printf("FLOAT : %s\n", yytext);
}

{INT} {
    printf("INTEGER : %s\n", yytext);
}

{ID} {
    printf("IDENTIFIER : %s\n", yytext);
}

"=="|"!="|"<="|">="|"="|"+"|"-"|"*"|"/"|"<"|">" {
    printf("OPERATOR : %s\n", yytext);
}

";"|","|"("|")"|"{"|"}" {
    printf("DELIMITER : %s\n", yytext);
}

"//".* {
    printf("COMMENT : %s\n", yytext);
}

[ \t\r\n]+   ;

. {
    printf("LEXICAL ERROR : %s\n", yytext);
}

%%

int yywrap(void)
{
    return 1;
}
