go:-
 nl,write('Enter a number: '),
 read(N),
 factorial(N,Res),
 nl,
 write('Factorial of '),write(N),write(' is '),
 write(Res),nl.


factorial(N,F) :- fact(N,1,F).
/* 
 * F contains the final result of factorial.
 */

fact(1,R,R) :- !.
/* 
 * second argument contains result.
 * unified with the third argument,
 * which is supposed to contain the final result. 
 */

fact(N,R1,R2) :- K is N*R1,
		 D is N-1,
		 fact(D,K,R2).
/* 
 * initially storing result as 1.
 * multiplies by N, and calls with N-1,
 * till 1.
 */
