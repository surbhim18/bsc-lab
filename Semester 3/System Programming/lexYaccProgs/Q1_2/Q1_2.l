%{
#include<stdio.h>
int noOfChars=0, noOfLines=0;
char fname[25];
%}

%%

\n	noOfLines++; noOfChars++;
.	noOfChars++;

%%

int main()
{
	printf("\nEnter the file name: ");
	scanf("%s",fname);
	yyin = fopen(fname,"r");
	
	yylex();
	
	printf("No. of lines:%d\nNo. of charaters: %d\n\n",noOfLines,noOfChars);

	return 0;
}

int yywrap()
{
	return 1;
}
