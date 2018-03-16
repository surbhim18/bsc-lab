%{
#include "y.tab.h"
%}

%%

[a-z]+[0-9]*		{ return ID;		}
[0-9]|[1-9][0-9]+	{ return NUM;		}

"="			{ return EQ;		}
"+"			{ return PLUS;		}
"-"			{ return MINUS;		}
"/"			{ return DIVIDE;	}
"*"			{ return MULTIPLY;	}

";"			{ return SEMICOLON;	}

" "*			{ ; }
\n			{ ; }

.    			{ printf("Unidentified token: %s\n",yytext);};

%%
