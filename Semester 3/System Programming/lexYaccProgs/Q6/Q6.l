%{
#include<stdio.h>
int noOfChars=0, noOfLines=0, noOfWords=0, noOfSpaces=0;
char fname[25];
%}

%%

[^ \t\n]+	noOfWords++; noOfChars+=yyleng;
" "		noOfChars++; noOfSpaces++;
"\t"		noOfChars++; noOfSpaces+=8;	
\n	        noOfLines++; noOfChars++;

%%

int main()
{
	printf("\nEnter the file name: ");
	scanf("%s",fname);
	yyin = fopen(fname,"r");
	
	yylex();
	
	printf("No. of words       : %d\n",noOfWords);
	printf("No. of characters  : %d\n",noOfChars);
	printf("No. of blank spaces: %d\n",noOfSpaces);
	printf("No. of lines       : %d\n\n",noOfLines);

	return 0;
}

int yywrap()
{
	return 1;
}
