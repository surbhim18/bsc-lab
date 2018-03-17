go:-
 nl,write('Enter first number : '),
 read(A),
 write('Enter second number: '),
 read(B),
 multiply(A,B,X),
 write('Product            : '),
 write(X).

multiply(X,0,0):-!.
multiply(X,1,X):-!.
multiply(X,Y,Res):- N is Y-1, multiply(X,N,R), Res is R+X.
