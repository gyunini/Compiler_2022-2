%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>   

  struct Symbol_Table
  {
     char sym_name[10];
     char sym_type[100];
     double value;
     int sym_offset;
  }Sym[10];

  int sym_cnt=0;
  int Index=0;
  int temp_var=1;
  int offset = 0;

  char arr_temp_type[100];
  char arr_temp_name[10];
  char arrName[10];
  char arr_first_temp_type[100];
  char arr_second_temp_type[100];
  int arrcnt = 0;
  int arrStmtCnt = 0;
  int arrcheck = 0;
  int lineNo = 1;

  int first_int_array_param = 0;
  int second_int_array_param = 0;
  char first_char_array_param[2];
  char second_char_array_param[2];



  int search_symbol(char []);
  char* search_symbol_type(char []);
  void make_symtab_entry(char [],char [],double);
  void display_sym_tab();  
  void addQuadruple(char [],char [],char [],char []);
  void display_Quadruple();
  void push(char*, char*);
  char* pop();
  char* make_arr_type(int, char[], char []);
 void strintrude (char *, char *, int);

  struct Quadruple
  {
    char operator[5];
    char operand1[10];
    char operand2[10];
    char result[10];
  }QUAD[25];

 struct Stack
  {
    char *items[10];
    char *types[10];
    int top;
  }Stk;

%}

%union
{
    int ival;          
    double dval;
    char string[10];
    int arrval;
}


%token <ival> INTEGER
%token <dval> DOUBLE
%token <string> TYPE
%token <string> ID
%type <string> varlist
%type <string> expr
%type <string> arrlist
%token MAIN
%left '+' '-'
%left '*' '/'
%right UMINUS
%right UPLUS


%%


program: MAIN '('')''{' body '}'
        | error  { yyerror('재입력하시오\n'); }
        ;
body: varstmt stmtlist
        ;

varstmt: vardecl varstmt
        |
        ;

// 변수 선언 -> 타입(int, double) + 리스트
vardecl: TYPE varlist ';' {lineNo++;}
       | TYPE arrlist ';' {lineNo++;}
        ;
// 변수 리스트 -> a, b, c, ....
varlist: varlist ',' ID {   // 콤마 변수 선언
                            int i;
                            i=search_symbol($3);
                            if(i!=-1)
                              yyerror("syntax error: Multiple Declaration of Variable");
                            else
                              make_symtab_entry($3,$<string>0,0); // $3를 테이블 엔트리에 저장, 타입은 string타입으로 $0(이 rule이 적용되기 전의 stack의 top위치), val은 0으로 초기화
                        }                                                               // TYPE varlist인데 varlist로 reduce되는 rule이기 때문에 이 rule이 적용되기 전에 top의 위치에 TYPE이 있음

        | ID            {                
                            int i;
                            i=search_symbol($1);
                            if(i!=-1)
                              yyerror("syntax error: Multiple Declaration of Variable");
                            else
                              make_symtab_entry($1,$<string>0,0);
                        }
        | error  
        ;
        
arrlist: ID '[' INTEGER ']'     {
                                    strcpy(arr_temp_name, $1);
                                    strcpy(arr_first_temp_type, $<string>0);
                                    char arr_type[30] = "array(";
                                    strcpy(arr_temp_type, make_arr_type($3, arr_first_temp_type, arr_type));
                                    arrcnt++;
                                    make_symtab_entry(arr_temp_name, arr_temp_type, 0);
                                } 

       | arrlist'[' INTEGER ']' {
                                    char* temp;
                                    char* temp1;
                                    char* temp2;
                                    char arr_type[30] = "array(";
                                    // printf("cnt: -----%d----\n", arrcnt);
                                    if(arrcnt>=2) {
                                      // printf("first: %s\n", arr_first_temp_type);
                                      strcpy(arr_second_temp_type, arr_first_temp_type);
                                      strcpy(arr_first_temp_type, "");
                                    }
                                    strcpy(arr_first_temp_type, make_arr_type($3, "int", arr_type)); // arr(3, int)
                                      if(arrcnt>=2) { // 3차원 배열 타입선언을 위한 코드
                                      memmove(arr_second_temp_type + (arrcnt-1)*8 + 1*(arrcnt-1), arr_first_temp_type, strlen(arr_first_temp_type));
                                      memmove(arr_temp_type + (arrcnt-1)*8 + 1*(arrcnt-1), arr_second_temp_type, strlen(arr_second_temp_type));
                                    } else {
                                      // printf("--\n");
                                      memmove(arr_temp_type + arrcnt*8 + 1*arrcnt, arr_first_temp_type, strlen(arr_first_temp_type));
                                    }
                                    make_symtab_entry(arr_temp_name, arr_temp_type, 0);
                                    arrcnt++;
                                  }

      |
      | error  
      ;
       

stmtlist: stmt stmtlist
        | arrstmt stmtlist
        |
        | error  
        ;
// a = 10; a = b;  c = b + d; 등의 지정문
stmt : ID '=' INTEGER ';' {
                            int i;
                            i=search_symbol($1);
                            if(i==-1)
                              printf("\n Undefined Variable");
                            else {
                              char temp[10];
                              if(strcmp(Sym[i].sym_type,"int")==0) // *****
                                sprintf(temp,"%d",(int)$3);
                              else
                                  snprintf(temp,10,"%f",$3);
                              addQuadruple("=","",temp,$1);
                              
                            }
                            lineNo++;
                   }

    | ID '=' DOUBLE ';' {
                            int i;
                            i=search_symbol($1);
                            if(i==-1)
                              printf("\n Undefined Variable");
                            else {
                              char temp[10];
                              if(strcmp(Sym[i].sym_type,"int")==0) // *****
                                sprintf(temp,"%d",(int)$3);
                              else
                                  snprintf(temp,10,"%f",$3);
                              addQuadruple("=","",temp,$1);
                            }
                            lineNo++;
                   }

    | ID '=' ID ';'{
                        int i,j;
                        i=search_symbol($1);
                        j=search_symbol($3);
                        if(i==-1 || j==-1)
                          printf("\n Undefined Variable");
                        else
                          addQuadruple("=","",$3,$1);
                        lineNo++;
                    }   

    | ID '=' expr ';'      { 
                              char* temp;
                              char* temp1;
                              char* um = "-";
                              temp = Stk.items[Stk.top];
                              temp1 = Stk.types[Stk.top];
                              // printf("stacktop: %s\n", temp);
                              if(strncmp(temp, um, 1) == 0) { // unary일 경우..
                                char str[5],str1[5]="t";
                                sprintf(str, "%d", temp_var);
                                strcat(str1,str);                   
                                temp_var++;
                                addQuadruple("=","",pop(),str1);
                                push(str1, temp1);
                                addQuadruple("=","",pop(),$1);
                              } else {
                                addQuadruple("=","",pop(),$1);
                              }
                              lineNo++;
                           }
      | error  


    ;
arrstmt: ID '[' INTEGER ']'         { first_int_array_param = $3; arrStmtCnt++;}

       | arrstmt '[' INTEGER ']'    { second_int_array_param = $3; arrStmtCnt++;}

       | ID '[' ID ']'          { strcpy(first_char_array_param, $3); arrStmtCnt++;}

       | arrstmt '[' ID ']'     { strcpy(second_char_array_param, $3); arrStmtCnt++;}

       | expr arrstmt ';'           // { printf("======\n"); }

       | ID '=' arrstmt ';' {
                      // printf("array 중간코드 생성 %d!!!\n", arrcnt);
                      int i;
                      char* k;
                      int t;
                      char*j;
                      char str[5],str1[5]="t";
                      char str2[5], str3[5] ="t";
                      char str4[5], str5[5] ="t";
                      sprintf(str, "%d", temp_var);    // 버퍼 str에 있는 t와 temp_var 0을 붙임 -> t0, t1 ..... 등 temporary 변수 생성
                      strcat(str1,str);
                      temp_var++;
                      for(i=0;i<sym_cnt;i++)
                      {
                        if(strncmp(Sym[i].sym_type, "array", 5)==0) // array타입이 심볼 테이블에 있는지 확인
                        {
                          j = Sym[i].sym_type;
                        }
                      }
                      // printf("---%s---\n", j);
                      // printf("---%s---\n", arr_temp_type);
                      // printf("---%c---\n", arr_temp_type[15]);
                      if(arrStmtCnt == 1) {
                          char s1[10];       // 변환한 문자열을 저장할 배열
                          // char s2[10];       // 변환한 문자열을 저장할 배열
                          // char s3[10];       // 변환한 문자열을 저장할 배열
                          if(first_int_array_param != 0){
                            printf("%d\n", first_int_array_param);
                            sprintf(s1, "%d", first_int_array_param);
                            printf("%s\n",s1);
                          }
                          if(first_char_array_param)
                            strcpy(s1, first_char_array_param);
                          // sprintf(s3, "%d", t);
                          addQuadruple("*", "4", s1, str1);
                          strcpy(arrName, arr_temp_name);
                          strcat(arrName, "[");
                          strcat(arrName, str1);
                          strcat(arrName, "]");
                          // printf("%s\n", arrName);
                          sprintf(str4, "%d", temp_var);
                          memmove(str5+1, str4, 1);
                          addQuadruple("=","", arrName, str5);
                      } else if (arrStmtCnt == 2) {
                        //addQuadruple("",pop(),pop(),str1);
                        // printf("first param, second param: %d %d\n", first_int_array_param, second_int_array_param);
                        
                        char s1[10];       // 변환한 문자열을 저장할 배열
                        char s2[10];       // 변환한 문자열을 저장할 배열
                        char s3[10];       // 변환한 문자열을 저장할 배열
                        
                        k = (arr_temp_type + 15);
                        // printf("%d\n", atoi(k));
                        t = atoi(k) * 4;
                        sprintf(s1, "%d", first_int_array_param);    // %d를 지정하여 정수를 문자열로 저장
                        if(first_char_array_param)
                          strcpy(s1, first_char_array_param);
                        sprintf(s2, "%d", second_int_array_param);    // %d를 지정하여 정수를 문자열로 저장
                        if(second_char_array_param)
                          strcpy(s2, second_char_array_param);
                        sprintf(s3, "%d", t);    // %d를 지정하여 정수를 문자열로 저장
                        // printf("first param, second param: %s %s\n", s1, s2);
                        // printf("%d\n",atoi(arr_temp_type[15]));
                        addQuadruple("*", s3, s1, str1);
                        sprintf(str2, "%d", temp_var);
                        strcat(str3,str2);
                        addQuadruple("*", "4", s2, str3);
                        temp_var++;
                        sprintf(str4, "%d", temp_var);
                        strcat(str5,str4);
                        addQuadruple("+", str3, str1, str5);
                        strcpy(arrName, arr_temp_name);
                        strcat(arrName, "[");
                        strcat(arrName, str5);
                        strcat(arrName, "]");
                        // printf("%s\n", arrName);
                        temp_var++;
                        sprintf(str4, "%d", temp_var);
                        memmove(str5+1, str4, 1);
                        addQuadruple("=","", arrName, str5);
                        push(str5, arr_temp_type);
                        addQuadruple("=","",pop(),$1);
                        temp_var++;
                      }
                      lineNo++;
                    }
        ;

expr : expr '+' expr  {
                        char str[5],str1[5]="t"; // 버퍼 선언
                        char str2[5], str3[5] ="t"; // 초기 temp_var = 0을 str버퍼에 저장
                        sprintf(str, "%d", temp_var);    // 버퍼 str에 있는 t와 temp_var 0을 붙임 -> t0, t1 ..... 등 temporary 변수 생성
                        strcat(str1,str);                   
                        temp_var++;                       // temp_var 증가
                        // printf("----%s----\n", Stk.types[Stk.top]);
                        // printf("----%s----\n", Stk.types[Stk.top-1]); // t1 = inttoreal r
                        if(strcmp(Stk.types[Stk.top-1], "double") == 0 && strcmp(Stk.types[Stk.top], "int") == 0) {
                            addQuadruple("",pop(), "inttoreal",str1); // result는 str1으로 -> t0..
                            push(str1, "double");
                            sprintf(str2, "%d", temp_var);
                            strcat(str3,str2);
                            temp_var++;
                            addQuadruple("+",pop(),pop(),str3);    // void addQuadruple(char op[10],char op2[10],char op1[10],char res[10])        
                            push(str3, "double");
                        } else if (strcmp(Stk.types[Stk.top], "double") == 0 && strcmp(Stk.types[Stk.top-1], "int") == 0) {
                            char* temp;
                            temp = pop(); // b
                            addQuadruple("",pop(), "inttoreal",str1);  // a inttoreal
                            push(str1, "double");
                            push(temp, "double");
                            sprintf(str2, "%d", temp_var);
                            strcat(str3,str2);
                            temp_var++;
                            addQuadruple("+",pop(),pop(),str3);    
                            push(str3, "double");
                        } else if (strcmp(Stk.types[Stk.top], "int") == 0 && strcmp(Stk.types[Stk.top-1], "int") == 0) {
                            addQuadruple("+",pop(),pop(),str1);    
                            push(str1, "int");
                        } else {
                            addQuadruple("+",pop(),pop(),str1);    
                            push(str1, "double");
                        }
                    }
    | expr '-' expr  {
                        char str[5],str1[5]="t"; // 버퍼 선언
                        char str2[5], str3[5] ="t"; // 초기 temp_var = 0을 str버퍼에 저장
                        sprintf(str, "%d", temp_var);    // 버퍼 str에 있는 t와 temp_var 0을 붙임 -> t0, t1 ..... 등 temporary 변수 생성
                        strcat(str1,str);                   
                        temp_var++;                       // temp_var 증가
                        // printf("----%s----\n", Stk.types[Stk.top]);
                        // printf("----%s----\n", Stk.types[Stk.top-1]); // t1 = inttoreal r
                        if(strcmp(Stk.types[Stk.top-1], "double") == 0 && strcmp(Stk.types[Stk.top], "int") == 0) {
                            addQuadruple("",pop(), "inttoreal",str1); // result는 str1으로 -> t0..
                            push(str1, "double");
                            sprintf(str2, "%d", temp_var);
                            strcat(str3,str2);
                            temp_var++;
                            addQuadruple("-",pop(),pop(),str3);    // void addQuadruple(char op[10],char op2[10],char op1[10],char res[10])        
                            push(str3, "double");
                        } else if (strcmp(Stk.types[Stk.top], "double") == 0 && strcmp(Stk.types[Stk.top-1], "int") == 0) {
                            char* temp;
                            temp = pop(); // b
                            addQuadruple("",pop(), "inttoreal",str1);  // a inttoreal
                            push(str1, "double");
                            push(temp, "double");
                            sprintf(str2, "%d", temp_var);
                            strcat(str3,str2);
                            temp_var++;
                            addQuadruple("-",pop(),pop(),str3);    
                            push(str3, "double");
                        } else if (strcmp(Stk.types[Stk.top], "int") == 0 && strcmp(Stk.types[Stk.top-1], "int") == 0) {
                            addQuadruple("-",pop(),pop(),str1);    
                            push(str1, "int");
                        } else {
                            addQuadruple("-",pop(),pop(),str1);    
                            push(str1, "double");
                        }
                    }  

    | expr '*' expr {
                    char str[5],str1[5]="t"; // 버퍼 선언
                        char str2[5], str3[5] ="t"; // 초기 temp_var = 0을 str버퍼에 저장
                        sprintf(str, "%d", temp_var);    // 버퍼 str에 있는 t와 temp_var 0을 붙임 -> t0, t1 ..... 등 temporary 변수 생성
                        strcat(str1,str);                   
                        temp_var++;                       // temp_var 증가
                        // printf("----%s----\n", Stk.types[Stk.top]);
                        // printf("----%s----\n", Stk.types[Stk.top-1]); // t1 = inttoreal r
                        if(strcmp(Stk.types[Stk.top-1], "double") == 0 && strcmp(Stk.types[Stk.top], "int") == 0) {
                            addQuadruple("",pop(), "inttoreal",str1); // result는 str1으로 -> t0..
                            push(str1, "double");
                            sprintf(str2, "%d", temp_var);
                            strcat(str3,str2);
                            temp_var++;
                            addQuadruple("*",pop(),pop(),str3);    // void addQuadruple(char op[10],char op2[10],char op1[10],char res[10])        
                            push(str3, "double");
                        } else if (strcmp(Stk.types[Stk.top], "double") == 0 && strcmp(Stk.types[Stk.top-1], "int") == 0) {
                            char* temp;
                            temp = pop(); // b
                            addQuadruple("",pop(), "inttoreal",str1);  // a inttoreal
                            push(str1, "double");
                            push(temp, "double");
                            sprintf(str2, "%d", temp_var);
                            strcat(str3,str2);
                            temp_var++;
                            addQuadruple("*",pop(),pop(),str3);    
                            push(str3, "double");
                        } else if (strcmp(Stk.types[Stk.top], "int") == 0 && strcmp(Stk.types[Stk.top-1], "int") == 0) {
                            addQuadruple("*",pop(),pop(),str1);    
                            push(str1, "int");
                        } else {
                            addQuadruple("*",pop(),pop(),str1);    
                            push(str1, "double");
                        }
                }      

    | expr '/' expr {
                        char str[5],str1[5]="t"; // 버퍼 선언
                        char str2[5], str3[5] ="t"; // 초기 temp_var = 0을 str버퍼에 저장
                        sprintf(str, "%d", temp_var);    // 버퍼 str에 있는 t와 temp_var 0을 붙임 -> t0, t1 ..... 등 temporary 변수 생성
                        strcat(str1,str);                   
                        temp_var++;                       // temp_var 증가
                        // printf("----%s----\n", Stk.types[Stk.top]);
                        // printf("----%s----\n", Stk.types[Stk.top-1]); // t1 = inttoreal r
                        if($3 == 0) {
                          yyerror('divide by zero');
                        } else if(strcmp(Stk.types[Stk.top-1], "double") == 0 && strcmp(Stk.types[Stk.top], "int") == 0) {
                            addQuadruple("",pop(), "inttoreal",str1); // result는 str1으로 -> t0..
                            push(str1, "double");
                            sprintf(str2, "%d", temp_var);
                            strcat(str3,str2);
                            temp_var++;
                            addQuadruple("/",pop(),pop(),str3);    // void addQuadruple(char op[10],char op2[10],char op1[10],char res[10])        
                            push(str3, "double");
                        } else if (strcmp(Stk.types[Stk.top], "double") == 0 && strcmp(Stk.types[Stk.top-1], "int") == 0) {
                            char* temp;
                            temp = pop(); // b
                            addQuadruple("",pop(), "inttoreal",str1);  // a inttoreal
                            push(str1, "double");
                            push(temp, "double");
                            sprintf(str2, "%d", temp_var);
                            strcat(str3,str2);
                            temp_var++;
                            addQuadruple("/",pop(),pop(),str3);    
                            push(str3, "double");
                        } else if (strcmp(Stk.types[Stk.top], "int") == 0 && strcmp(Stk.types[Stk.top-1], "int") == 0) {
                            addQuadruple("/",pop(),pop(),str1);    
                            push(str1, "int");
                        } else {
                            addQuadruple("/",pop(),pop(),str1);    
                            push(str1, "double");
                        }
                    }    

    | '(' expr ')'  

    | '-' expr %prec UMINUS   {
                                char* temp;
                                char temp1[5] = "-";
                                temp = pop();
                                strcat(temp1, temp);   // int snprintf ( char * s, size_t n, const char * format, ... ); 버퍼에 저장, 크기만큼 리턴
                                push(temp1, "int");
                              }

    | '+' expr %prec UPLUS  // 어차피 10++a는 그냥 +처럼 해주면 돼서 할게 없음

    | ID {                     
        int i;
        char* j;
        i=search_symbol($1);
        j = search_symbol_type($1);
        //printf("-----%s type: %s-----\n",$1 ,j);
        if(i==-1) // symbol table에 없는 경우
          printf("\n Undefined Variable\n");
         else // 있으면 index i리턴
          push($1, j);              
        }

    | DOUBLE {       
                char temp[10]; // 버퍼 선언
                snprintf(temp,10,"%f",$1);   // int snprintf ( char * s, size_t n, const char * format, ... ); 버퍼에 저장, 크기만큼 리턴
                push(temp, "double");               // 저장된 버퍼를 스택에 push
            }

    | INTEGER {       
                char temp[10]; // 버퍼 선언
                snprintf(temp,10,"%d",$1);   // int snprintf ( char * s, size_t n, const char * format, ... ); 버퍼에 저장, 크기만큼 리턴
                push(temp, "int");               // 저장된 버퍼를 스택에 push
            }
    ;


%%

extern FILE *yyin;
int main()
{
   
  Stk.top = -1; // 스택의 top을 -1로 초기화
  yyin = fopen("input.txt","r");
  yyparse();
  display_sym_tab();
  printf("\n\n");
  display_Quadruple();
  printf("\n\n");
  return(0);
}


void strintrude (char *s, char *t, int i) 
{     
/*문자열 s의 i 번째 위치에 문자열 t를 삽입*/ 
  int cnt; 
  char string[100], *temp = string; 
  for(cnt = 0 ; cnt < 100 ; cnt++) // init 
    string[cnt] = '\0';
  if( i < 0 && i > (int)strlen(s)) 
  {         
    fprintf(stderr, "position is out of bounds \n");         
    exit (1);         
  } 
  if (!strlen(s))         
  { 
    strcpy (s, t);         
  } 
  else if (strlen(t))  
  {     
    strcat(t,(s+i)); 
    strcpy((s+i),t); 
  }     
}

char* make_arr_type(int num, char type[10], char* arr_type)
{
  // char* arr_type = malloc(30);
  // strcpy(arr_type, "array(");
  char s[10];       // 변환한 문자열을 저장할 배열
  sprintf(s, "%d", num); 
  // printf("%s\n", s);
  strcat(arr_type, s);
  strcat(arr_type, ", ");
  strcat(arr_type, type);
  strcat(arr_type, ")");
  // printf("%s\n", arr_type);
  return arr_type;
}

int search_symbol(char sym[10])
{
  int i,flag=0;
  for(i=0;i<sym_cnt;i++)
  {
    if(strcmp(Sym[i].sym_name,sym)==0) // 심볼 테이블에 있는지 확인
    {
      flag=1;
      break;
    }
  }
  if(flag==0) // 없는 경우
    return(-1);
  else        // 있는 경우
    return(i);
}
char* search_symbol_type(char sym[10])
{
  int i;
  char*j;
  for(i=0;i<sym_cnt;i++)
  {
    if(strcmp(Sym[i].sym_name,sym)==0) // 심볼 테이블에 있는지 확인
    {
      return Sym[i].sym_type;
    }
  }
  return NULL;
}

void make_symtab_entry(char sym[10],char dtype[10],double val)
{
  for(int i=0;i<sym_cnt;i++) { // 이차원 배열 심볼테이블에 덮어쓰기
    if (strcmp(Sym[i].sym_name, sym) == 0) { // 같은게 있으면
      strcpy(Sym[i].sym_name,sym);
      strcpy(Sym[i].sym_type,dtype);
      Sym[i].value=val;
      Sym[i].sym_offset = offset;
      offset += 8;
      return;
    }
  }
  strcpy(Sym[sym_cnt].sym_name,sym);
  strcpy(Sym[sym_cnt].sym_type,dtype);
  Sym[sym_cnt].value=val; // 변수선언시에 0으로 저장
  if(strcmp(Sym[sym_cnt].sym_type, "int") == 0) {
    Sym[sym_cnt].sym_offset = offset;
    offset += 4;
  } else {
    Sym[sym_cnt].sym_offset = offset;
    offset += 8;
  }
  sym_cnt++;
}


void display_sym_tab()
{
  int i;
  printf("------------The Symbol Table--------\n\n");
  printf(" Name   Type    offset    Value");
  for(i=0;i<sym_cnt;i++)
    printf("\n %s      %s    %d       %f",Sym[i].sym_name,Sym[i].sym_type, Sym[i].sym_offset, Sym[i].value);
  printf("\n\n------------------------------------\n");
}
void display_Quadruple()
{
  int i;
  printf("----------INTERMEDIATE CODE---------\n");
  //printf("\n     Result  Operator  Operand1  Operand2  ");
  for(i=0;i<Index;i++) {
   //printf("\n %d     %s          %s          %s          %s",i,QUAD[i].result,QUAD[i].operator,QUAD[i].operand1,QUAD[i].operand2);
    if (strcmp(QUAD[i].operator, "=") == 0)
      printf("%s = %s\n", QUAD[i].result, QUAD[i].operand1);
    else 
      printf("%s = %s %s %s\n", QUAD[i].result, QUAD[i].operand1, QUAD[i].operator, QUAD[i].operand2);
  }
  printf("------------------------------------\n");
}

int yyerror(char const *s, int charCnt)
{
    if(strcmp(s, "lexical error") == 0) {
      fprintf(stderr, "%s(%d:%d)\n", s, lineNo, charCnt);
      return -1;
    } else {
      fprintf(stderr, "%s(%d)\n", s, lineNo);
      return -1;
    }
}

// 스택에 push하는 함수
void push(char *str, char* type) 
{
  Stk.top++; // 초기 -1
  Stk.items[Stk.top]=(char *)malloc(strlen(str)+1);
  strcpy(Stk.items[Stk.top],str);
  Stk.types[Stk.top]=(char *)malloc(strlen(type)+1);
  strcpy(Stk.types[Stk.top],type);
}
char * pop()
{
  int i;
  if(Stk.top==-1)
  {
     printf("\nStack Empty!! \n");
     exit(0);
  }
  char *str=(char *)malloc(strlen(Stk.items[Stk.top])+1);;
  strcpy(str,Stk.items[Stk.top]);
  free(Stk.items[Stk.top]);
  free(Stk.types[Stk.top]);
  Stk.top--;
  return(str);
}

void addQuadruple(char op[10],char op2[10],char op1[10],char res[10])
 {
    strcpy(QUAD[Index].operator,op);
    strcpy(QUAD[Index].operand2,op2);
    strcpy(QUAD[Index].operand1,op1);
    strcpy(QUAD[Index].result,res);
    Index++;
}



/*
int r; 
double pi; 
r = 5; 
pi = 3.14; 
area = pi * r * r; 
cir = pi * r + pi * r;

r = 5
pi = 3.14
t1 = inttoreal r
t2 = pi * t1
t3 = inttoreal r
t4 = t2 * t3
area = t4
t5 = inttoreal r
t6 = pi * t5
t7 = inttoreal r
t8 = pi * t7
t9 = t6 + t8
cir = t9
*/

//에러처리
// int a d c;
// b = 10 a;