//
//  main.c
//  Lexical_Analyzer
//
//  Created by 이균 on 2022/10/02.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <inttypes.h>
#include <ctype.h>

/* To avoid security error on Visual Studio */
#define _CRT_SECURE_NO_WARNINGS
#define MAX_COMMAND    256 /* Maximum length of command string */
#pragma warning(disable : 4996)

typedef unsigned char bool;
#define true    1
#define false    0

char* strings[100];
char* symbols[100];
int strIndex = 0;
int idIndex= 0;
int errLine = 1;

bool isValidDelimiter(char ch) {
   if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
   ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
   ch == '<' || ch == '=' || ch == ':' || ch == '\n' || ch == '\0')
   return (true);
   return (false);
}

bool isSemiColone(char ch) {
    if (ch == ';') {
        return true;
    } else return false;
}

bool isValidOperator(char ch){
   if (ch == '+' || ch == '-' || ch == '*' ||
   ch == '/' || ch == '>' || ch == '<' ||
   ch == '=' || ch == ':')
   return (true);
   return (false);
}

bool isvalidIdentifier(char* str){
   int i, len = strlen(str);
   bool mid_digit = false;
    
   if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
   str[0] == '3' || str[0] == '4' || str[0] == '5' ||
   str[0] == '6' || str[0] == '7' || str[0] == '8' ||
   str[0] == '9' || str[0] == '"' || isValidDelimiter(str[0]) == true)
       return (false);
    
    if(!((str[0] >= 0x30 && str[0] <= 0x57) || (str[0] >= 0x41 && str[0] <= 0x5A) || (str[0] >= 0x61 && str[0] <= 0x7A))) {
        return false;
    }
 
    for (i = 1; i < len-1; i++) {
        if((str[i] >= 0x30 && str[i] <= 0x57) || (str[i] >= 0x41 && str[i] <= 0x5A) || (str[i] >= 0x61 && str[i] <= 0x7A))
        {
            if( str[i] >= 0x30 && str[i] <= 0x57)
            {
                mid_digit = true;
            }
            else{
                if(mid_digit)
                    return (false);
            }
        }
        else
            return false;
    }
    
    if(mid_digit) {
        if (str[len-1] == '0' || str[len-1] == '1' || str[len-1] == '2' ||
        str[len-1] == '3' || str[len-1] == '4' || str[len-1] == '5' ||
        str[len-1] == '6' || str[len-1] == '7' || str[len-1] == '8' ||
        str[len-1] == '9')
            return (true);
        else{
            return (false);
        }
    }
    
    if(!((str[len-1] >= 0x30 && str[len-1] <= 0x57) || (str[len-1] >= 0x41 && str[len-1] <= 0x5A) || (str[len-1] >= 0x61 && str[0] <= 0x7A)))
        return false;
    
   return (true);
}
bool isValidString(char* str) {
    if (str[0] == '"')
        return true;
    else
        return false;
}
bool isValidKeyword(char* str) {
   if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") ||    !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "int")
   || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str,    "char") || !strcmp(str, "case") || !strcmp(str, "char")
   || !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned")
   || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto"))
   return (true);
   return (false);
}
bool isValidInteger(char* str) {
   int i, len = strlen(str);
   if (len == 0)
   return (false);
   for (i = 0; i < len; i++) {
      if (str[i] != '0' && str[i] != '1' && str[i] != '2'&& str[i] != '3' && str[i] != '4' && str[i] != '5'
      && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
      return (false);
   }
   return (true);
}
bool isRealNumber(char* str) {
   int i, len = strlen(str);
   bool hasDecimal = false;
   if (len == 0)
   return (false);
   for (i = 0; i < len; i++) {
      if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i]       != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8'
      && str[i] != '9' && str[i] != '.' || (str[i] == '-' && i > 0))
      return (false);
         if (str[i] == '.')
      hasDecimal = true;
   }
   return (hasDecimal);
}
char* subString(char* str, int left, int right) {
   int i;
   char* subStr = (char*)malloc( sizeof(char) * (right - left + 2));
   for (i = left; i <= right; i++)
      subStr[i - left] = str[i];
   subStr[right - left + 1] = '\0';
   return (subStr);
}
void detectTokens(char* str) {
   int left = 0, right = 0;
   bool stringCheck = true;
   int length = strlen(str);
   bool findId = false;
    bool findString = false;
   while (right <= length && left <= right) {
       findId = false;
       findString = false;
       if(str[right] == '"')
       {
           right++;
           while(str[right] != '"') {
               right++;
               if(str[right] == '\0') {
                   stringCheck = false;
                   break;
               }
           }
           if(!stringCheck) {
               printf("Error: line %d \t\t%s\n",errLine ,str);
               break;
           }
           
       }
      if (isValidDelimiter(str[right]) == false)
          right++;
      if (isValidDelimiter(str[right]) == true && left == right) {
         if (isValidOperator(str[right]) == true)
         {
             if(str[right] == '=')
                 printf("<ASSIGN, > \t\t%c\n", str[right]);
             else if (str[right] == '+')
                 printf("<PLUS, > \t\t%c\n", str[right]);
             else if (str[right] == '-')
                 printf("<MINUS, > \t\t%c\n", str[right]);
             else if (str[right] == '*')
                 printf("<MUL, > \t\t%c\n", str[right]);
             else if (str[right] == '/')
                 printf("<DIV, > \t\t%c\n", str[right]);
             else if (str[right] == ':')
                 printf("<COLON, > \t\t%c\n", str[right]);
             else if (str[right] == '<')
                 printf("<LESS, > \t\t%c\n", str[right]);
             else if (str[right] == '>')
                 printf("<GREATER, > \t\t%c\n", str[right]);
         }
         else if (isSemiColone(str[right]) == true) {
             printf("<SEMICOLON, > \t\t;\n");
         }
         right++;
         left = right;
      } else if (isValidDelimiter(str[right]) == true && left != right || (right == length && left !=       right)) {
         char* subStr = subString(str, left, right - 1);
         if (isValidKeyword(subStr) == true)
            printf("<KEYWORD, %s>\t%s\n", subStr, subStr);
         else if (isValidInteger(subStr) == true)
            printf("<INT, %s> \t\t%s\n", subStr, subStr);
         else if (isRealNumber(subStr) == true)
            printf("<REAL, %s>\t\t%s\n", subStr, subStr);
         else if (isvalidIdentifier(subStr) == true && isValidDelimiter(str[right - 1]) == false)
         {
             if(strlen(subStr) > 10) {
                 subStr[10] = '\0';
             }
             for (int i = 0; i < idIndex; i++)
             {
                 if(!strcmp(subStr, symbols[i])) {
                     printf("<ID, %d> \t\t%s\n", i + 1, subStr);
                     findId = true;
                     break;
                 }
             }
             if (findId == false) {
                 symbols[idIndex] = subStr;
                 printf("<ID, %d> \t\t%s\n", idIndex+1, subStr);
                 idIndex++;
             }
         }
         else if (isValidString(subStr) == true)
         {
             for (int i = 0; i < strIndex; i++) // 중복체크
             {
                 if(!strcmp(subStr, strings[i])) {
                     printf("<STRING, %d> \t\t%s\n", i + 1, subStr);
                     findString = true;
                     break;
                 }
             }
             if (findString == false) {
                 strings[strIndex] = subStr;
                 printf("<STRING, %d> \t\t%s\n", strIndex +1, subStr);
                 strIndex++;
             }
         }
         else if (isvalidIdentifier(subStr) == false && isValidDelimiter(str[right - 1]) == false)
         printf("Error: line %d \t\t%s\n",errLine ,subStr);
         left = right;
      }
   }
   return;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    char command[MAX_COMMAND] = {'\0'};
    FILE *input = stdin;

    if (argc > 1) {
        input = fopen(argv[1], "r");
        if (!input) {
            perror("Input file error");
            return EXIT_FAILURE;
        }
    }
    printf("<Lexical Analyzer Program>\n\n");
    printf("======TOKEN LIST======\n");
    printf("TOKEN\t\t%s\n","LEXEME");
    while (fgets(command, sizeof(command), input)) {
        detectTokens(command);
        errLine++;
        printf("\n");
    }
    printf("=======================\n\n");
    printf("======STRING TABLE=====\n");
    for (int i = 0; i < strIndex; i++) {
        printf("index = %d \t strings = %s\n", i+1, strings[i]);
    }
    printf("=======================\n");
    printf("\n\n");
    
    printf("======<SYMBOL TABLE>=====\n");
    for (int i = 0; i < idIndex; i++) {
        printf("index = %d \t symbols = %s\n", i+1, symbols[i]);
    }
    
    printf("=======================\n");
    if (input != stdin) fclose(input);
    printf("\n");
    return EXIT_SUCCESS;
}

