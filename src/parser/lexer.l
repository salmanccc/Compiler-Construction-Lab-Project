%{
#include <stdio.h>
#include "parser.tab.h"
%}

LETTER  [a-zA-Z_]
DIGIT   [0-9]
ID      {LETTER}({LETTER}|{DIGIT})*

%%

"int"           { return INT; }
"float"         { return FLOAT; }
"print"         { return PRINT; }

{ID}            { return ID; }

[0-9]+          { return NUMBER; }

"="             { return '='; }
";"             { return ';'; }
"("             { return '('; }
")"             { return ')'; }

[ \t\n]+        ;

.               { return yytext[0]; }

%%

int yywrap(void)
{
    return 1;
}
