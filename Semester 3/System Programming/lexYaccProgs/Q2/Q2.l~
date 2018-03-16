%{
#include<stdio.h>
%}

%%

[a-z]	{
		char ch;
		ch = yytext[0];
		ch+=3;
			
		if(ch>'z')
		   ch=ch-26;

		printf("%c",ch);
	}	
			

[A-Z]	{
		char ch;
		ch = yytext[0];
		ch+=3;
			
		if(ch>'Z')
		   ch=ch-26;

		printf("%c",ch);
	}	
%%

int main()
{
	yylex();	

}

int yywrap()
{
	return 1;
}
