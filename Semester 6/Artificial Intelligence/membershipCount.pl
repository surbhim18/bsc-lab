go:-
 nl,write('Enter a list : '),
 read(L),
 nl,write('Enter element: '),
 read(E),
 myCount(E,L,C),
 write('Count is: '),write(C).

myCount(X,[],0).
/*
 * base case for list: when the list is empty,
 * the count of X in list is 0.
 */

myCount(X,[X|Y],C) :- myCount(X,Y,C1), C is C1+1.   
/*
 * when we find the element, we find the element in
 * the remaining list and add one to the count,
 * till the list is exhausted.
 */

myCount(X,[H|T],C) :- X\=H, myCount(X,T,C).	
/*
 * X\=H is used because we cannot use cut with the
 * previous predicate, because it will stop execution
 * after first successful search. To ensure this predicate 
 * isn't used, we specify X\=H
 */

