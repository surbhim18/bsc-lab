ordered([X]):-!.
ordered([H1|[H2|T]]) :- H1=<H2, ordered([H2|T]).
