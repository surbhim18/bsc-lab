go:-
    nl,write('Enter a tree: '),
    read(T),nl,
    write('DFS Traversal:'),nl,
    dfs(T),nl.

dfs(nil):-!.
dfs(T) :- T=t(X,Y,Z), write(Y), write(' '), dfs(X),dfs(Z).
