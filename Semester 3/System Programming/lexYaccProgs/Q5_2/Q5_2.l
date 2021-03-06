%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char fname[25];
char str[100];
int noOfIdens=0;
%}

%%

[0-9]|[1-9][0-9]+				;

[0-9]\.[0-9]+|[1-9][0-9]*\.[0-9]+		;

[A-Za-z]+.h					;

"auto"|"break"|"case"|"const"			;
"continue"|"default"|"do"			;
"else"|"enum"|"extern"|"for"			;
"printf"|"scanf"|"include"|"main"		;
"goto"|"if"|"long"|"register"			;
"return"|"short"|"signed"|"sizeof"		;
"static"|"struct"|"switch"|"typedef"		;
"union"|"unsigned"|"void"|"volatile"|"while"	;

("float"|"int"|"char"|"double").*\;		{ 
							int i=0; strcpy(str,yytext);
							
							while(str[i]!='\0')
							{
								if(str[i]==',')
									noOfIdens++;
								
								i++;
							}
							noOfIdens++;
						}

"//".*						; 
		
"/*"(.*\n*)*"*/"				;		 

"+"|"-"|"/"|"*"|"%"|"="|"=="		 	;

[ \t\n;]					;

.						;




%%

int main()
{
	printf("\nEnter the file name: ");
	scanf("%s",fname);
	yyin = fopen(fname,"r");

	yylex();

	printf("\nThe no of identifiers in the C file: %d\n\n", noOfIdens);

	return 0;
}

int yywrap()
{
	return 1;
}
