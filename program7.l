//Krishnapriya Deepak
%{ 
#include<stdio.h> 
int vowels=0,consonants=0; 
%} 
%% 
[aeiouAEIOU] vowels++; 
[\t ' ' .] ECHO; 
. consonants++; 
%% 
 
void main() 
{ 
 FILE *fp=fopen("input.txt","r"); 
 yyin=fp; 
 yylex(); 
 printf("\nVowels:%d",vowels); 
 printf("\nConsonants:%d",consonants); 
 fclose(fp); 
} 
int yywrap() 
{ 
 return 1; 
} 
/*  
Input: My name is Abhishek. I am a CSE student. 
 OUTPUT 
Vowels:12 
Consonants:18 
*/