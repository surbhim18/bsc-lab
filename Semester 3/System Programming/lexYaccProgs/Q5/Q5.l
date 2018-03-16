%{
#include<stdio.h>
#include<stdlib.h>

char fname[25];
int noOfIdens=0;
%}

%%

[0-9]|[1-9][0-9]+				;

[0-9]\.[0-9]+|[1-9][0-9]*\.[0-9]+		;

[A-Za-z]+.h					;

"auto"|"break"|"case"|"char"|"const"		;
"continue"|"default"|"do"|"double"		;
"else"|"enum"|"extern"|"float"|"for"		;
"printf"|"scanf"|"include"|"main"				;
"goto"|"if"|"int"|"long"|"register"		;
"return"|"short"|"signed"|"sizeof"		;
"static"|"struct"|"switch"|"typedef"		;
"union"|"unsigned"|"void"|"volatile"|"while"	;


"//".*						; 
		
"/*"(.*\n*)*"*/"				;		 

"+"|"-"|"/"|"*"|"%"|"="|"=="		 	;

[A-Z_a-z][A-Za-z_0-9]*				{ printf( "%s : is an identifier\n" , yytext); noOfIdens++;}

[ \t\n;]					;

.						;




%%

int main()
{
	printf("\nEnter the file name: ");
	scanf("%s",fname);
	yyin = fopen(fname,"r");

	yylex();

	printf("\nThe no of idenmtifiers in the C file: %d\n\n", noOfIdens);

	return 0;
}

int yywrap()
{
	return 1;
}
