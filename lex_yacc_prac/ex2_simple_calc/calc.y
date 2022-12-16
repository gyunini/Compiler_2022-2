%{ // 간단한 수식 계산기의 .y .l 파일 분리 예제 -> 멀티라인은 못함
#include <stdio.h>
extern int yylex();
extern void yyerror(const char*);
%}

%token NUM

%%

line: expr '\n'         { printf("%d\n", $1); } 
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

// -v옵션 -> calc.output -> DFA