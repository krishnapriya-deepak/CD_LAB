/*Krishapriya Deepak S7CS230
Program 3*/

#include<stdio.h>
#include<string.h>
struct prod{
	char l[10];
	char r[10];
}rules[50];
char st[50];
int top=0;
int total=0;

int reducable()
{
	int a,i=0;
	if(!strcmp(st,"$S"))
	{
		return 0;
	}
	for(i=0;i<total;i++)
	{
		a=strlen(rules[i].r);
		int temptop=top;
		int flag=0;
		for(int j=a-1;j>=0;j--)
		{
			if(rules[i].r[j]==st[--temptop])
				continue;
			else
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			break;
		}
		else
			continue;
	}
	if(i<total)
	{
		top-=strlen(rules[i].r);
		st[top++]=rules[i].l[0];
		st[top]='\0';
		printf("REDUCE \t|\t|\t%s \n",st);
		return 1;
	}
	return 0;
}

int parsable(char *str)
{
	st[top++]='$';
	st[top]='\0';
	for(int i=0;i<strlen(str);i++)
	{
		st[top++]=str[i];
		st[top]='\0';
		printf("SHIFT \t|\t|\t%s \n",st);
		while(reducable());
	}
	if(strcmp(st,"$S"))
		return 1;
	else
		return 0;
}

void main()
{
	char gmr[50];
	char str[50];
	printf("Enter number of production rules:");
	scanf("%d",&total);
	printf("Enter production rules:\n");
	for(int i=0;i<total;i++)
	{
		scanf("%s",gmr);
	        rules[i].l[0]=gmr[0];
	        for(int j=3;j<strlen(gmr);j++)
	        {
	        	rules[i].r[j-3]=gmr[j];
	        }
	        strcpy(gmr," ");
	 }
	 printf("Enter string to be parsed:");
	 scanf("%s",str);
	 if(!parsable(str))
	 	printf("ACCEPTED \nIt can be parsed");
	 else
	 	printf("The string cannot be parsed");
	}


	
/* OUTPUT
Enter number of production rules:4
Enter production rules:
S->(L)
S->A
L->L,S
L->S
Enter string to be parsed:(A,(A,A))
SHIFT 	|	|	$( 
SHIFT 	|	|	$(A 
REDUCE 	|	|	$(S 
REDUCE 	|	|	$(L 
SHIFT 	|	|	$(L, 
SHIFT 	|	|	$(L,( 
SHIFT 	|	|	$(L,(A 
REDUCE 	|	|	$(L,(S 
REDUCE 	|	|	$(L,(L 
SHIFT 	|	|	$(L,(L, 
SHIFT 	|	|	$(L,(L,A 
REDUCE 	|	|	$(L,(L,S 
REDUCE 	|	|	$(L,(L 
SHIFT 	|	|	$(L,(L) 
REDUCE 	|	|	$(L,S 
REDUCE 	|	|	$(L 
SHIFT 	|	|	$(L) 
REDUCE 	|	|	$S 
ACCEPTED 
It can be parsed
*/
