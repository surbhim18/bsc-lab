%{
#include<stdio.h>
#include<string.h>

int len=0;
char str[100];
char fname[25];

%}

%%

[A-Za-z]+	{
			if(yyleng > len)
			{
				len = yyleng;
				strcpy(str,yytext);
			}
		}

.|\n		;	
		
%%

int main()
{
	printf("\nEnter the file name: ");
	scanf("%s",fname);
	yyin = fopen(fname,"r");

	yylex();
	
	printf("\nThe string with maximum length is \"%s\" with length = %d\n\n",str,len);	

	return 0;
}

int yywrap()
{
	return 1;
}
