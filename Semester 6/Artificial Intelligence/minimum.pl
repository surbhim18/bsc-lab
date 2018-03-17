go:-
    nl,write('Enter first number : '),read(A),
    write('Enter second number: '),read(B),
    min(A,B,Res),
    write('Minimum : '),write(Res),nl.

min(A,B,Res):- A<B,Res=A,!.
min(_,B,B).
