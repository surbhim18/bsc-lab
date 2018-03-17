

rev([X],[X]):-!.
rev([X|T],L) :- rev(T,R), append(R,[X],L).

palindrome(L) :- rev(L,L).
