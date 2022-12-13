%{
#include "y.tab.h"
%}

%%

[1-9][0-9]* { yylval = atoi(yytext); return NUM;}
[ \t] ; // ignore white space
\n |
.           return yytext[0]; // . => \n을 제외한 모든 글자 (정규표현의 정의)

%%

/*
flex calc.l
bison -d -b y calc.y    -d: y.tab.h생성, -b y: y.tab.c생성
gcc -o calc y.tab.c lex.yy.c -lfl
./calc
*/

