likes(mary,snake):-animal(snake),!,fail.
likes(mary,X):-animal(X).

animal(bird).
animal(monkey).
animal(snake).
