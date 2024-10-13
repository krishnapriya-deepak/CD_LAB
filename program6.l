//Exp 6 
%{ 
#include<stdio.h> 
%} 
%% 
[a-z] { 
 yytext[0]=yytext[0]-32; 
 printf("%c",yytext[0]); 
 } 
%% 
 
void main() 
{ 
 FILE *fp=fopen("input.txt","r"); 
 yyin=fp; 
  
 yylex(); 
 fclose(fp); 
} 
int yywrap() 
{ 
 return 1; 
} 
 
/* 
Input: My name is A. I am 20. 
 OUTPUT 
MY NAME IS A. I AM 20.*/