%{
#include<stdio.h>

int len;
%}

%%

[A-Za-z]+	{
			len = yyleng;
			int i,j;

			printf("\n");
			for(i=len; i>=1; i--)
			{
				for(j=0; j<i; j++)
					printf("%c",yytext[j]);

				printf("\n");				
			}
			printf("\n");
			
		}

\n		;
.		;	

%%

int main()
{
	yylex();	

	return 0;
}

int yywrap()
{
	return 1;
}
