go:-
 nl,write('Enter a list               : '),
 read(L),
 write('Enter element to be deleted: '),
 read(E),
 delete_first(E,L,X),
 write('Deleted list               : '),
 write(X),nl.

delete_first(X,[X|T],T):-!.
delete_first(X,[H|T],[H|T1]) :- delete_first(X,T,T1).

/*
 * Or use,
 *
 * delete_first(X,[X|T],T).
 * delete_first(X,[H|T],[H|T1]) :- X\=H,delete_first(X,T,T1).
 *
 * Or use,
 *
 * delete_first(X,[X|T],L):-L is T,!.
 * delete_first(X,[H|T],[H|T1]) :- delete_first(X,T,T1).
 *
 */
