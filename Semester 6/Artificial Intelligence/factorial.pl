go:-
 nl,write('Enter a number: '),
 read(N),N>0,
 factorial(N,Res),
 write('Factorial of '),write(N),write(': '),
 write(Res),nl,!.

go:- write('Error!'),nl.

factorial(0,1):-!.
factorial(N,Fact):- N1 is N-1,
		    factorial(N1,F1),
		    Fact is N*F1.











