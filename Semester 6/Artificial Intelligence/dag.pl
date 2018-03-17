go:-
    nl,write('Enter starting node : '),
    read(A),
    write('Enter finishing node: '),
    read(B),
    route(A,B),nl,
    write('Path exists.'),nl,!.

go:-
    nl,write('No path exists.'),nl.


route(A,B) :- edge(A,B),!.
route(A,B) :- edge(A,X), route(X,B).

edge(p,q).
edge(q,r).
edge(q,s).
edge(s,t).
