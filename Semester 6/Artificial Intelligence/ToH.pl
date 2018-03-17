go:- nl,write('Enter no. of disks: '), read(N),nl,
     toh(N).

toh(N) :- move(N,left,right,middle).

move(0,_,_,_):- !.
move(1,A,B,_):- inform(A,B),!.

move(N,A,B,C):- M is N-1,
		move(M,A,C,B),
		inform(A,B),
		move(M,C,B,A).

inform(A,B)  :- write('Move disk from '),write(A),write(' to '),write(B),write('.'),nl.















