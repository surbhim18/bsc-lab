%{
#include<stdio.h>
%}

%token A B DELIM

%%

start:	anbm	DELIM	{ printf("\nIt is a valid AnBm"); return; }

anbm:	an bm

an:	A |
	A an

bm:	B |
	B bm

%%

int main()
{
	char ch;

	do
	{
		printf("\nEnter a string:\n");
		yyparse();

		printf("\n\nDo you wish to continue (y/n) :  \n");
		scanf("%c", &ch);

		getchar();

	}while(ch=='y'||ch=='Y');
	
	return 0;	
}

int yywrap()
{
	return 1;
}

yyerror(s)
char* s;
{
	fprintf(stderr,"%s\n\n",s);
}
