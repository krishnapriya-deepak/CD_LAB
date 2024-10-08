/*Krishnapriya Deepak S7CS230
Program1:Lexical Analyser */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_LEN 1000
#define MAX_TOKENS 100
typedef struct{
	char token[MAX_LEN];
}Token;
	
void readFile(char *filename,char *buffer);
void lexical(char *src);
int findToken(Token tokens[],int tokencount,const char *token);


int main()
{
	char src[MAX_LEN];
	readFile("source.c",src);
	lexical(src);
	return 0;
}
void readFile(char *filename,char *buffer)
{
	FILE *file=fopen(filename,"r");
	if(file==NULL){
		printf("\nError in opening file");
		return;
		}
	char ch;
	int i=0;
	while((ch=fgetc(file))!=EOF && i<MAX_LEN-1)
	{
		buffer[i++]=ch;
	}
	buffer[i]='\0';
	fclose(file);
}
void lexical(char *src)
{
	char token[MAX_LEN];
	Token tokens[MAX_TOKENS];
	int tokencount=0;
	FILE *fp=fopen("sym.txt","w");
	int i=0;
	while(src[i]!='\0')
	{
		if(isspace(src[i]))
		{
			i++;
			continue;
		}
		switch(src[i])
		{
			case 'v':
				if(strncmp(&src[i],"void",4)==0)
				{
					
					printf("Token:<Keyword:void>\n");
					
					strcpy(tokens[tokencount].token,"void");
					tokencount++;
					i+=4;
					
				}
				break;
			case 'm':
				if(strncmp(&src[i],"main",4)==0)
				{
					printf("Token:<Keyword:main>\n");
					strcpy(tokens[tokencount].token,"main");
					tokencount++;
					i+=4;
				}
				break;
			case 'i':
				if(strncmp(&src[i],"int",3)==0)
				{
					printf("Token:<Keyword:int>\n");
					strcpy(tokens[tokencount].token,"int");
					tokencount++;
					i+=3;
				}
				else if(strncmp(&src[i],"if",2)==0)
				{
					printf("Token:<Keyword:if>\n");
					strcpy(tokens[tokencount].token,"if");
					tokencount++;
					i+=2;
				}
				break;
			case 'p':
				if(strncmp(&src[i],"printf",6)==0)
				{
					printf("Token:<Keyword:printf>\n");
					strcpy(tokens[tokencount].token,"printf");
					tokencount++;
					i+=6;
				}
				break;
			case '>':case'=':
				printf("Token:<Operator:%c>\n",src[i]);
				sprintf(tokens[tokencount].token,"%c",src[i]);
					tokencount++;
				i++;
				break;
			case '"':
				i++;
				int j=0;
				while(src[i]!='"' && src[i]!='\0')
				{
					token[j++]=src[i++];
				}
				token[j]='\0';
				if(src[i]=='"')
				{
					i++;
				}
				printf("Token:<String:\"%s\">\n",token);
				strcpy(tokens[tokencount].token,token);
					tokencount++;
				break;
				
			default:
				if(isalpha(src[i]))
				{
					int j=0;
					while(isalnum(src[i]))
					{
						token[j++]=src[i++];
					}
					token[j]='\0';
					if(!findToken(tokens,tokencount,token))
					{
						printf("Token:<Identifier:%s>\n",token);
						fprintf(fp,"<Identifier:%s>\n",token);
						strcpy(tokens[tokencount].token,token);
						tokencount++;
					}
					
				}
				else if(isdigit(src[i]))
				{
					int j=0;
					while(isdigit(src[i]))
					{
						token[j++]=src[i++];
					}
					token[j]='\0';
					if(!findToken(tokens,tokencount,token))
					{
						printf("Token:<Value:%s>\n",token);
						strcpy(tokens[tokencount].token,token);
						tokencount++;
					}
				}
				else
				{
					i++;
					continue;
				}
				break;
			fclose(fp);
			}
			
		}
}
int findToken(Token tokens[],int tokencount,const char *token){
	for(int i=0;i<tokencount;i++)
	{
		if(strcmp(tokens[i].token,token)==0)
		{
			return 1;
		}
	}
	return 0;
}

/*Output
Source Program
void main(){
int xy=10,ac=5;
if(xy > ac)
printf("Greater");
}

Terminal
Token:<Keyword:void>
Token:<Keyword:main>
Token:<Keyword:int>
Token:<Identifier:xy>
Token:<Operator:=>
Token:<Value:10>
Token:<Identifier:ac>
Token:<Operator:=>
Token:<Value:5>
Token:<Keyword:if>
Token:<Operator:>>
Token:<Keyword:printf>
Token:<String:"Greater">


Symbol Table
<Identifier:xy>
<Identifier:ac>

*/
