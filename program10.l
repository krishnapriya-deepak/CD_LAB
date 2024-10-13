//exp 10 
%{ 
#include <stdio.h> 
#include <string.h> 
FILE *output_file; 
#define IDENTIFIER  
#define NUMBER 2 
#define KEYWORD 3 
#define OPERATOR 4 
#define WHITESPACE 5 
#define STRING 6 
#define SYMBOL 7 
%} 
KEYWORD "if"|"else"|"while"|"for"|"int"|"else if"|"printf" 
OPERATOR "*"|"-"|"+"|"=" 
SYMBOL "{"|"}"|"("|")"|";" 
%% 
{KEYWORD} {fprintf(output_file,"Keyword :%s\n",yytext);} 
{SYMBOL} {fprintf(output_file,"Symbol :%s\n",yytext);} 
[0-9]+ {fprintf(output_file,"NUmber :%s\n",yytext);} 
[a-zA-Z_][a-zA-Z0-9_]* {fprintf(output_file,"Identifier :%s\n",yytext);} 
{OPERATOR} {fprintf(output_file,"Operator :%s\n",yytext);} 
"\""[^"]*"\"" {fprintf(output_file,"String :%s\n",yytext);} 
[ \t\n]+  {} 
. {fprintf(output_file,"Unknown Character :%s\n",yytext);} 
%% 
int main(int argc, char **argv){ 
FILE *input_file = fopen("input.txt","r"); 
output_file = fopen("output.txt","w"); 
yyin = input_file; 
yylex(); 
fclose(input_file); 
fclose(output_file); 
return 0; 
} 
/*OUTPUT 
//input.txt 
int main(){ 
int a = 5; 
int b=6; 
int c=10; 
printf("Sum is %d",a+b+c); 
return 0; 
} 
//output.txt 
Keyword :int 
Identifier :main 
Symbol :( 
Symbol :) 
Symbol :{ 
Keyword :int 
Identifier :a 
Operator := 
NUmber :5 
Symbol :; 
Keyword :int 
Identifier :b 
Operator := 
NUmber :6 
Symbol :; 
Keyword :int 
Identifier :c 
Operator := 
NUmber :10 
Symbol :; 
Keyword :printf 
Symbol :( 
String :"Sum is %d" 
Unknown Character :, 
Identifier :a 
Operator :+ 
Identifier :b 
Operator :+ 
Identifier :c 
Symbol :) 
Symbol :; 
Identifier :return 
NUmber :0 
Symbol :; 
Symbol :}