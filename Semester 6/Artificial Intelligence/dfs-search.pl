go:-
    nl,write('Enter a tree: '),
    read(T),nl,
    write('Enter element: '),read(Ele),
    dfs(T,Ele),nl,write('Element not found.'),!.
	
go:-
	nl,write('Element found.').
	
dfs(nil,_):-!.
dfs(T,Ele) :- T=t(X,Y,Z),Y==Ele,!,fail.
dfs(T,Ele) :- T=t(X,Y,Z),dfs(X,Ele),dfs(Z,Ele).
