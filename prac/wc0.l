/* 
* [ONLY USING FLEX] 
* https://www.oreilly.com/library/view/flex-bison/9780596805418/ch01.html 참고 
*  아래 커멘드로 실행가능
* $ flex fb1-1.l
* $ cc lex.yy.c -lfl
* $ ./a.out
*
*/


%{
int chars = 0;
int words = 0;
int lines = 0;
#define LETTER 1
#define DIGIT 2
#define BLANK 3
%}

blank [\t\n]+
letter [a-zA-Z]+
digit [0-9]

%%

{letter}  { words++; chars += strlen(yytext); return LETTER;}
{blank}    { chars++; lines++; return}
{digit}    {return DIGIT;}
.        { chars++; }

%%

int main(int argc, char **argv)
{
  // yylex();
  // printf("%8d%8d%8d\n", lines, words, chars);
  int tok;
  while(( tok = yylex() )!= 0) {
    if(tok == LETTER)
      printf("letter\n");
    else if(tok == DIGIT)
      printf("digit\n");
    else
      printf("blank\n");
    printf("%8d%8d%8d\n", lines, words, chars);
  }
}
