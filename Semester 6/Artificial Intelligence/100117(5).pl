likes(mary,X):-snake(X),!,fail.
likes(mary,X):-animal(X).

animal(bird).
animal(monkey).
snake(python).
snake(cobra).
