%a
elemento([Y|T], X):-
    X =:= 1, write(Y), !;
    elemento(T, (X - 1)).
    
%b nao feita
lista_impar([], L2).
lista_impar([H|T], L2):-
    H mod 2 =:= 0, lista_impar(T, L2), !;
    H mod 2 =:= 1, lista_impar(T, [H | L2]).

%c
inverte([], X):-
    write(X).
inverte([H | T], X):-
    inverte(T, [H | X]).

%d
nroOcorrencias([], X, Y).
nroOcorrencias([H | T], X, Y):-
    H = X, Aux is (Y + 1), nroOcorrencias(T, X, Aux);
    nroOcorrencias(T, X, Y).