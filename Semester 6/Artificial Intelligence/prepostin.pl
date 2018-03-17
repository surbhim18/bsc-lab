go:-
    nl,write('Enter a tree: '),
    read(T),nl,
    write('Preorder : '),pre(T),nl,
    write('Inorder  : '),in(T),nl,
    write('Postorder: '),post(T),nl.

pre(nil):-!.
pre(T) :- T=t(X,Y,Z), write(Y), write(' '), pre(X),pre(Z).

in(nil):-!.
in(T) :- T=t(X,Y,Z), in(X), write(Y), write(' '), in(Z).

post(nil):-!.
post(T) :- T=t(X,Y,Z), post(X),post(Z),write(Y), write(' ').
