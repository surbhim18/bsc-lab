go:-
    nl,write('Enter a tree: '),
    read(T),nl,
    write('BFS Traversal:'),nl,
    dfs(T),nl.

bfs(nil):-!.
bfs(T) :- T=t(X,Y,Z), write(Y), write(' '), dfs(X),dfs(Z).
