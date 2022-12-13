%{ // ambiguous grammar일때 token 정의에서 precedence, associativity를 주는 예제 멀티라인 안됨
#include <stdio.h>
extern int yylex();
extern void yyerror(const char*);
%}

%token NUM
%left '-''+'
%left '*'
%right UMINUS

%%

lines: expr '\n'         { printf("%d\n", $1); } 
    | lines'\n'
    | // empty
    ;
expr: expr '+' expr     { $$ = $1 + $3; }      // '+' => terminal symbol은 single quoted
    | expr '-' expr     { $$ = $1 - $3; }
    | expr '*' expr     { $$ = $1 * $3; }
    | '-'expr %prec UMINUS  { $$ = -$2; }       // -의 precedence를 따르지 않고 UMINUS precedence를 따름 => **** 1+-5 를 계산하면 -4가 출력됨 *******
    |'(' expr ')'           { $$ = $2; }
    | NUM                   { $$ = $1; }
    ;

// ambiguous이기 때문에 아래 rule이 필요 없음 , 더 간단함

//     | term              
//     ;
// term: term '*' factor   { $$ = $1 * $3; }
//     | factor
//     ;
// factor: '(' expr ')'    { $$ = $2; }
//     | NUM
//     ;

%%

void yyerror(const char* msg)
{
    fprintf(stderr, "%s\n", msg);
}

int main() {
    yyparse();
    return 0;
}