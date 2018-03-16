%{
#include<stdio.h>
#include<string.h>

int len=0;
char str[100];

%}

%%

[A-Za-z]+	{
			if(yyleng > len)
			{
				len = yyleng;
				strcpy(str,yytext);
			}
		}

\n		{ return; }
.		;	

%%

int main()
{
	yylex();
	
	printf("\nThe string with maximum length is \"%s\" with length = %d\n\n",str,len);	

	return 0;
}

int yywrap()
{
	return 1;
}
