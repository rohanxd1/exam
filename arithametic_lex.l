%{
#include "y.tab.h"
%}
%%
[a-zA-Z_][a-zA-Z_0-9]* return id;
[0-9]+(\.[0-9]*)? return num;
[+/*] return op;
. return yytext[0];
\n return 0;
%%
int yywrap()
{
return 1;
}


output:
yacc -d  arithametic_yacc.y
lex arithametic_lex.l
gcc lex.yy.c y.tab.c -w
./a.out
