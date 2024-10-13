//arith.y 
%{ /* Definition Section*/ 
#include<stdio.h> 
#include<stdlib.h> 
int yylex(void); 
int yyerror(char* s); 
%} 
%token NUMBER ID 
%left '+''-' 
%left '*''/''%' 
%left '('')' 
%% 
/*grammer production rule*/ 
expr: expr '+' expr 
|expr'-'expr 
|expr'*'expr 
|expr'/'expr 
|'-'NUMBER 
|'-'ID 
|'('expr')' 
|NUMBER 
|ID 
%% 
int main(){ 
printf("Enter the expression\n"); 
yyparse(); 
printf("Expression is valid\n"); 
return 0; 
} 
/* For printing error messages */ 
int yyerror(char* s){ 
printf("\nExpression is invalid"); 
exit(0); 
} 


//OUTPUT 
1) Enter the expression 
a+b 
Expression is valid 
2) Enter the expression 
)a+b 
Expression is invalid