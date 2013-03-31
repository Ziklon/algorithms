repetidos([],[]):-!.
repetidos([X|Xs],S):-contar(X,Xs,C),(C>0-> repetidos(Xs,S1), concatenar(S1,[],S); repetidos(Xs,S1), concatenar(S1,[X],S)).
