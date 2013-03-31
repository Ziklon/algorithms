% Autor:
% Fecha: 23/10/2012
arco(a,b,2).
arco(a,c,3).
arco(b,c,2).
arco(c,d,3).
arco(b,d,4).
ruta(E1,d,[E1,d],C):- arco(E1,d,C).
ruta(E1,d,[E1|Zs],C):- arco(E1,E2,C1),
                       ruta(E2,d,Zs,C2),
                       C is C1+C2.

sumarL([],0):-!.
sumarL([X|Lr],S):- sumarL(Lr,S1),S is X+S1.

buscar(X,[]):- write('Dato no encontrado'),!.
buscar(X,[X|Xs]):- write('Dato encontrado'),!.
buscar(X,[Y|Xs]):- buscar(X,Xs).

eliminar(X,[],[]):-!.
eliminar(X,[X|Xs],Zs):-eliminar(X,Xs,Zs).
eliminar(X,[Y|Xs],[Y|Zs]):-eliminar(X,Xs,Zs).

contar(X,[],0):-!.
contar(X,[X|Xs],C):- contar(X,Xs,C1),C is 1+C1.
contar(X,[Y|Xs],C):- contar(X,Xs,C).

concatenar([],Ys,Ys):-!.
concatenar([X|Xs],Ys,[X|Zs]):-concatenar(Xs,Ys,Zs).


invertir([],[]):-!.
invertir([X|Xs],Ys):-invertir(Xs,Yr),concatenar(Yr,[X],Ys).
maximo(A,B,Max):-(A>B->Max is A; Max is B).

repetidos([],[]):-!.
repetidos([X|Xs],Ys):-repetidos(Xs,Z1),eliminar(X,Z1,S1),concatenar([X],S1,Ys).
