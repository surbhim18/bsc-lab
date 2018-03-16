%{
#include<stdio.h>
%}

%token	ID NUM
%token	EQ PLUS MINUS MULTIPLY DIVIDE
%token	LBKT RBKT SEMICOLON

// %associativity precedence (low to high) 
%right EQ
%left PLUS MINUS
%left MULTIPLY DIVIDE

%%

Start:	stmt SEMICOLON	{ printf("\nThis is a valid expression.");	return;	}

stmt: 	assign

assign:	ID EQ expr

expr:	factor	|
	expr PLUS expr	|
	expr MINUS expr	|
	expr MULTIPLY expr	|
	expr DIVIDE expr	|
	LBKT expr RBKT	

factor:	ID	|
	NUM

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
