%{
#include <stdio.h>
extern int yylex();
extern void yyerror(const char*);
double vbltable[26];  /* double형의 기억장소 배열 */
%}

%union  {
    double dval;
    int vblno;
}

%token    <vblno> NAME
%token    <dval> NUMBER
%left '-' '+'
%left '*' '/'
%nonassoc UMINUS
%type <dval> expression

%%

statement_list: statement '\n'
          |     statement_list statement '\n'
          |     //empty
          |     error '\n'  {yyerror("reenter last time");}              // yacc의 error recovery 추가!!
          ;
statement:        NAME '=' expression  { vbltable[$1] = $3; }
          |   expression                 { 
                                            printf("= %g\n",$1); 
                                            for (int i = 0; i < 26; i++) {
                                                if(vbltable[i] != 0)
                                                    printf("index: %d table value: %f\n", i, vbltable[i]);
                                            }
                                        }
          ;
expression: expression '+' expression  { $$ = $1 + $3;  }
          | expression '-' expression  { $$ = $1 - $3;  }
          | expression '*' expression  { $$ = $1 * $3;  }
          | expression '/' expression
                    {  if($3 == 0.0)
                             yyerror("divide by zero");
                       else   $$ = $1 /$3;
                    }
           |  '-'expression  %prec UMINUS   { $$ = -$2; }
           |  '('expression')'     { $$ = $2; }
           |       NUMBER
           |       NAME       { $$ = vbltable[$1]; }
           ;
%%

void yyerror(const char* msg)
{
    fprintf(stderr, "%s\n", msg);
}

int main()
{
    yyparse();
    return 0;
}