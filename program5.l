%{ 
#include<stdio.h> 
int lines=0,word=0,chars=0,letter=0,num=0,spl_char=0; 
%} 
%% 
\n {lines++;word++;} 
[\t ' '] word++; 
[a-zA-Z] letter++; 
[0-9] num++; 
. spl_char++; 
%% 
void main() 
{ 
FILE *fp=fopen("input.txt","r"); 
yyin=fp; 
yylex(); 
chars=letter+num+spl_char; 
printf("Words:%d\n",word); 
printf("Lines:%d\n",lines); 
printf("Total charachters:%d\n",chars); 
fclose(fp); 
} 
int yywrap() 
{ 
return 1; 
}

/* 
Input: Hello there. Nice to meet you. 
OUTPUT 
Words:6 
Lines:1 
Total charachters:29 
*/