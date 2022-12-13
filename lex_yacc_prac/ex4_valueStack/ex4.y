%{ // double type의 value stack을 정의 , 여러줄 가능하게 rule 수정함
#include <stdio.h>
extern int yylex();
extern void yyerror(const char*);
#define YYSTYPE double
%}

%token NUM

%%

lines: expr '\n'         { printf("%lf\n", $1); }  // double -> %f로 바꿔줘야함
    | lines  expr '\n'   { printf("%lf\n", $2); } // 여러줄이 가능해졌다!!!!!!!!!!!!!!!!!!!!!!!!!!!!, 3*5+(1+2)와 같은것도 잘 수행함
    ;
expr: expr '+' term     { $$ = $1 + $3; }      // '+' => terminal symbol은 single quoted
    | term              
    ;
term: term '*' factor   { $$ = $1 * $3; }
    | factor
    ;
factor: '(' expr ')'    { $$ = $2; }
    | NUM
    ;

%%

void yyerror(const char* msg)
{
    fprintf(stderr, "%s\n", msg);
}

int main() {
    yyparse();
    return 0;
}