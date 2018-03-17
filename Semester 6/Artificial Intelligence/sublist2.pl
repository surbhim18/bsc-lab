/*
 * Looks for exact order of sublist.
 */

go:-
 nl,write('Enter a list    : '),
 read(L),
 write('Enter a sublist : '),
 read(S),
 isSublist(S,L).
 

isSublist(S,L):- append(L1,L2,L),
		 append(S,L3,L2).

/*
 * use conc instead of append
 *
 * conc([],List,List).
 * conc([X|L1],L2,[X|L3]):- conc(L1,L2,L3).
 *
 */
