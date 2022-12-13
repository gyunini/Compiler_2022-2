%{
// 인터넷 에제
/* need this for the call to atof() below */
// -lfl속성 넣어주는거 까먹지 말기!!!!!!!!!!!!!!!!!!!!!!1
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
%}

DIGIT    [0-9]  
ID       [a-z][a-z0-9]*

%%
{DIGIT}+  { printf( "An integer: %s (%d)\n", yytext, atoi( yytext ) ); }
{DIGIT}+"."{DIGIT}* { printf( "A float: %s (%g)\n", yytext, atof( yytext ) ); }
if|then|begin|end|procedure|function { printf( "A keyword: %s\n", yytext ); }
{ID}   { printf( "An identifier: %s\n", yytext ); }
"+"|"-"|"*"|"/"  { printf( "An operator: %s\n", yytext ); }
"{"[^}\n]*"}"  ; /* { } 안의 내용은 주석으로 무시한다. */
[ \t\n]+  ; /* whitespace를 무시한다. */
.   printf( "Unrecognized character: %s\n", yytext );
%%

int main( int argc, char* argv[] ) {
    if ( argc > 1 ) {
            yyin = fopen( argv[1], "r" );
    }
    else
            yyin = stdin;
    yylex();
    return 0;
}

