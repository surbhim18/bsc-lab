go:-
 nl,write('Enter a list    : '),
 read(L),
 maxlist(L,X),
 write('Largest element : '),
 maxlist(L,X),
 write(X),nl.

max(X,Y,M):- X>Y,M=X,!.
max(_,Y,Y).

maxlist([X],X) :- !.
maxlist([H|T],M) :- maxlist(T,M1), max(H,M1,M).


