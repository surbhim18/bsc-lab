%{
#include<stdio.h>
#include<string.h>

char fname[25];
char str[100];
int noOfIdens=0;
%}

keywords "auto"|"break"|"case"|"const"|"continue"|"default"|"do"|"else"|"enum"|"extern"|"for"|"printf"|"scanf"|"include"|"main"|"goto"|"if"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"

type "char"|"int"|"float"|"double"

identifier [_a-zA-Z][_a-zA-Z0-9]*

id_dec {type}" "+{identifier}(" "*," "*{identifier})*" "*";"

%%

{keywords}  	{ ; }

{id_dec}    	{   
			strcpy(str,yytext);
			printf("%s\n",str);
                	int i=0;
                	while(str[i]!='\0') 
			{   
				if(str[i]==',')
				{ 
					noOfIdens++;
				} 
				i++;
			}
                	noOfIdens++;
            	}

"//".*		{ ; }
\n  		{ ; }
.   		{ ; }

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
