%{
#define YYSTYPE double // 얘를 안추가하면 오류남
#include "y.tab.h"
%}

%%

([0-9]+|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)     { yylval = atof(yytext); return NUM;}
[ \t] ; // ignore white space
\n |
.           return yytext[0]; // . => \n을 제외한 모든 글자 (정규표현의 정의)

%%