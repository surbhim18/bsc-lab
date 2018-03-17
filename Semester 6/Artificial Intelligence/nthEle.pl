go:-
 nl,write('Enter a list  : '),
 read(L),
 write('Enter position: '),
 read(N),
 nth_ele(N,L,X),
 write('Element       : '),
 write(X),nl.

nth_ele(1,[X|T],X):-!.
nth_ele(N,[H|T],X):- N1 is N-1, nth_ele(N1,T,X).
