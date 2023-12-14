%{
#include<stdio.h>
int sc=0,wc=0,lc=0,cc=0;
%}
%%
[\n] { lc++; cc+=yyleng;}
[ \t] { sc++; cc+=yyleng;}
[^\t\n ]+ { wc++; cc+=yyleng;}
%%
int main(int argc ,char* argv[])
{
printf("Enter the input:\n");
yylex();
printf("The number oflines=%d\n",lc);
printf("The number ofspaces=%d\n",sc);
printf("The number ofwords=%d\n",wc);
printf("The number ofcharacters are=%d\n",cc);
}
int yywrap()
{
return 1;
}