go:-
    nl,write('Enter list: '),
    read(L),nl,
    write('List with duplicates removed:'),nl,
    removeDup(L,R),write(R),nl.

removeDup([],[]):-!.
removeDup([H|T],L):- member(H,T),removeDup(T,L),!.
removeDup([H|T1],[H|T2]):- removeDup(T1,T2).
