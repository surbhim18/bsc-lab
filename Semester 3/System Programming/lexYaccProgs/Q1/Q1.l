%{
#include<stdio.h>
int noOfChars=0, noOfWords=0, noOfLines=0;
char fname[25];
%}

%%
[" \t"]+	noOfWords++;
\n		noOfLines++; noOfChars++; noOfWords++;
.		noOfChars++;

%%

int main()
{
	printf("\nEnter the file name: ");
	scanf("%s",fname);
	yyin = fopen(fname,"r");
	
	yylex();
	
	printf("No. of characters:%d\nNo. of words:%d\nNo. of lines: %d\n\n",noOfChars,noOfWords,noOfLines);

	return 0;
}

int yywrap()
{
	return 1;
}
