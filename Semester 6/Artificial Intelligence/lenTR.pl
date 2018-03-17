length_of(L,C) :- len(L,0,C).

len([],X,C) :- X=C,!.
len([H|T],X,C) :- K is X+1, len(T,K,C).
