%{
#include<stdio.h>
#include<string.h>
#include "y.tab.h"
int charCnt = 1;
char t[2] = "_";
%}

%%
[ \n\t]+ ;
main {return MAIN;}
int|float|double|char {strcpy(yylval.string,yytext); return TYPE; }
[a-zA-Z][a-zA-Z0-9]*    {strcpy(yylval.string,yytext);return ID; }
[0-9]+ {
          yylval.ival=atoi(yytext);
          return INTEGER;
       }
[0-9]+\.[0-9]+   {
          yylval.dval=atof(yytext);
          return DOUBLE;
                 }
[a-zA-Z][a-zA-Z0-9]*[_]+[0-9]+                   { 
                                                 //   printf("%s\n", yytext);
                                                   for(int i = 0; i < yyleng; i++) {
                                                        // printf("%c\n", *(yytext + i));
                                                        if(strncmp((yytext + i), t, 1) == 0) {
                                                               charCnt = i;
                                                               // printf("%d\n", charCnt);
                                                        }
                                                   }
                                                   yyerror("lexical error", charCnt);
                                                 }

[0-9]+[a-zA-Z|0-9|_]+                                 {yyerror("lexical error", 1);}
. {return yytext[0];}
%%

int yywrap(){
return 1;
}