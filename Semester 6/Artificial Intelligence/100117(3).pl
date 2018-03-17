max(X,Y,Res):- X>Y,!,X=Res.
max(_,Y,Y).
