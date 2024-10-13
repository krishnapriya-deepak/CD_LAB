%{ 
#include<stdio.h> 
#include"y.tab.h" 
#include<stdlib.h> 
int yyerror(char* s); 
int yylval; 
%} 
%% 
[0-9]+ {return NUMBER;} 
[a-zA-Z]+ {return ID;} 
[ \t]+ {;}/*For skipping whitespaces*/ 
\n {return 0;} 
. {return yytext[0];} 
%% 
int yywrap() 
{ 
return 1; 
}