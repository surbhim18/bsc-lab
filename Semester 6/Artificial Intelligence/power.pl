go:-
 nl,write('Enter number  : '),
 read(A),
 write('Enter exponent: '),
 read(B),
 power(A,B,X),nl,
 write(A),write('^'),write(B),write('  : '),
 write(X).

power(_,0,1):-!.
power(X,1,X):-!.
power(X,Y,Res):- N is Y-1, power(X,N,R), Res is R*X.



