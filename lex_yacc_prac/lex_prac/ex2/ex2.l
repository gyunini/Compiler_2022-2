%{ 
    // lex 튜토리얼 pdf파일 예제
    int yylineno;
%}

%%
^(.*)\n printf("%4d\t%s", ++yylineno, yytext);
%%

int main(int argc, char *argv[])
{
    yyin = fopen(argv[1], "r");
    yylex();
    fclose(yyin);
}