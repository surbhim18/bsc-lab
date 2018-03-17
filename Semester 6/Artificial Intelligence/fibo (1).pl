go:-
 nl,write('Enter number : '),
 read(A),
 generate_fib(A).


generate_fib(0) :- !.
generate_fib(N) :- N1 is N-1, generate_fib(N1), fibo(N,Res), write(Res), write(' '). 

fibo(1,0) :- !.
fibo(2,1) :- !.
fibo(N,T) :- N1 is N-1, N2 is N-2, fibo(N1,R1), fibo(N2,R2), T is R1 + R2.
/*
 * when n>2
 */
