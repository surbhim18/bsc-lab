%{
#include<stdio.h>
#include<stdlib.h>

char fname[25];
%}

%%

[0-9]|[1-9][0-9]+				{ printf("%d : is an integer\n", atoi(yytext)); }

[0-9]\.[0-9]+|[1-9][0-9]*\.[0-9]+		{ printf("%s : is a float\n", yytext); }

[A-Za-z]+.h					{ printf("%s : is a header file\n" , yytext); }

"alignas"|"alignof"|"and"|"and_eq"|"asm"	{ printf( "%s : is a keyword\n" ,yytext); }
"auto"|"bitand"|"bitor"|"bool"|"break"|"case"	{ printf( "%s : is a keyword\n" ,yytext); }
"catch"|"char"|"char16_t"|"char32_t"|"cin"	{ printf( "%s : is a keyword\n" ,yytext); }
"class"|"compl"|"concept"|"const"|"constexpr"	{ printf( "%s : is a keyword\n" ,yytext); }
"const_cast"|"continue"|"cout"|"decltype"	{ printf( "%s : is a keyword\n" ,yytext); }
"default"|"delete"|"do"|"double"|"dynamic_cast"	{ printf( "%s : is a keyword\n" ,yytext); }
"else"|"enum"|"explicit"|"export"		{ printf( "%s : is a keyword\n" ,yytext); }
"extern"|"false"|"float"|"for"|"friend"		{ printf( "%s : is a keyword\n" ,yytext); }
"goto"|"if"|"include"|"inline"|"int"|"long"	{ printf( "%s : is a keyword\n" ,yytext); }
"mutable"|"main"|"namespace"|"new"|"noexcept"	{ printf( "%s : is a keyword\n" ,yytext); }
"not_eq"|"nullptr"|"operator"|"or"|"or_eq"	{ printf( "%s : is a keyword\n" ,yytext); }
"private"|"protected"|"public"|"register"	{ printf( "%s : is a keyword\n" ,yytext); }
"reinterpret_cast"|"requires"|"return"		{ printf( "%s : is a keyword\n" ,yytext); }
"short"|"signed"|"sizeof"|"static"		{ printf( "%s : is a keyword\n" ,yytext); }
"static_assert"|"static_cast"|"struct"|"switch"	{ printf( "%s : is a keyword\n" ,yytext); }
"template"|"this"|"thread_local"|"throw"|"true"	{ printf( "%s : is a keyword\n" ,yytext); }
"try"|"typedef"|"typeid"|"typename"|"union"	{ printf( "%s : is a keyword\n" ,yytext); }
"unsigned"|"using"|"virtual"|"void"|"volatile"	{ printf( "%s : is a keyword\n" ,yytext); }
"wchar_t"|"while"|"xor"|"xor_eq"|"not"		{ printf( "%s : is a keyword\n" ,yytext); }

"//".*						{ printf( "%s\n: is a single line comment\n" ,yytext); }
		
"/*"(.*\n*)*"*/"				{ printf( "%s\n: is a multi-line comment\n", yytext); }

"+"|"-"|"/"|"*"|"="|"=="|"%"			 { printf( "%s : is an operator\n" , yytext); }

[A-Z_a-z]+					{ printf( "%s : is an identifier\n" , yytext);	}

[ \t\n;]						;

.						{ printf( "%s : unidentified character\n" ,yytext); }

%%

int main()
{
	printf("\nEnter the file name: ");
	scanf("%s",fname);
	yyin = fopen(fname,"r");

	yylex();

	return 0;
}

int yywrap()
{	return 1;
}

