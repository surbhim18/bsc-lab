enjoys(ram,chicken):-burger(chicken),!,fail.
enjoys(ram,X):-burger(X).

burger(chicken).
burger(cheese).
burger(veg).
