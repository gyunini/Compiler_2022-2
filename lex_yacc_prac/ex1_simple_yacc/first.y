%{ // .y만 사용하는 예제 -> 간단한 수식계산기 - 한 라인밖에 못함 멀티라인은 구현 안됨, 멀티라인 -> syntax error // 여러줄 가능
#include <stdio.h>
#include <ctype.h>
extern int yylex();
extern void yyerror(const char*);
%}

%token DIGIT

%%

line: expr '\n'         { printf("%d\n", $1); } 
    | line expr '\n'    { printf("%d\n", $2); }   // -> 여러줄 가능한 grammar  추가
    ;
expr: expr '+' term     { $$ = $1 + $3; }      // '+' => terminal symbol은 single quoted
    | term              
    ;
term: term '*' factor   { $$ = $1 * $3; }
    | factor
    ;
factor: '(' expr ')'    { $$ = $2; }
    | DIGIT
    ;

%%

int yylex() {
    int c;
    c = getchar();
    if(isdigit(c)) {
        yylval = c - '0';
        return DIGIT;
    }
    return c;
}

void yyerror(const char* msg)
{
    fprintf(stderr, "%s\n", msg);
}

int main()
{
    yyparse();
    return 0;
}

// 실행
/*
bison first.y
gcc -o first first.tab.c
./first
*/