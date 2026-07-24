%{
#include <stdio.h>
%}

%%
"int"           { printf("KEYWORD : %s\n", yytext); }
"float"         { printf("KEYWORD : %s\n", yytext); }
"if"            { printf("KEYWORD : %s\n", yytext); }
"while"         { printf("KEYWORD : %s\n", yytext); }

[0-9]+          { printf("NUMBER : %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]* {
    printf("IDENTIFIER : %s\n", yytext);
}

"="             { printf("OPERATOR : %s\n", yytext); }

";"             { printf("DELIMITER : %s\n", yytext); }

[ \t\n]+        ;

.               { printf("UNKNOWN : %s\n", yytext); }

%%

int yywrap() {
    return 1;
}