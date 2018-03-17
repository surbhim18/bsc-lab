go:-
    nl,write('Enter list: '),
    read(L),nl,
    write('List with duplicates removed:'),nl,
    removeDup(L,R),write(R),nl.

removeDup([],L):- !.
removeDup([H|T],L):- member(H,L),removeDup(T,L),!.
removeDup([H|T],L):- append(L,[H],L1),removeDup(T,L1).
