go:-
 nl,write('Enter a number: '),
 read(E),
 sum(E,X),
 write('Sum of digits : '),
 write(X).


sum(0,0):-!.
sum(N,Res):- M is (N mod 10), K is (N//10),
	     sum(K,R), Res is R+M.

/*
 * or use,
 *
 * sum(N,N):-N<10.
 * sum(N,Res):- N>=10,M is (N mod 10), K is floor(N\/10), 
 *		sum(K,R), Res is R+M.
 *
 */
