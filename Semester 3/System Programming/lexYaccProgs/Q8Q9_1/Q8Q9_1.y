%{
#include<stdio.h>
%}

%token	ID NUM
%token	EQ PLUS MINUS MULTIPLY DIVIDE
%token	SEMICOLON

%%

Start:	stmt SEMICOLON	{ printf("\nThis is a valid expression.");	return;	}
stmt: 	assign

assign:	ID EQ expr

expr:	term	|
	expr PLUS term	|
	expr MINUS term	
	

term:	factor	|
	term MULTIPLY factor	|
	term DIVIDE factor	

factor:	ID	|
	NUM	|
	expr

%%

int main()
{
	char ch;

	do
	{
		printf("\nEnter a  expression:\n");
		yyparse();

		printf("\n\nDo you wish to continue (y/n) :  \n");
		scanf("%c", &ch);

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
