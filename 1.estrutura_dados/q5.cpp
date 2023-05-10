/*
Considere um grupo de 14 pessoas. Suponha que a comunicação entre as pessoas deste grupo esteja representada através do grafo, onde os vértices representam as pessoas e as arestas representam a possibilidade de comunicação entre duas pessoas. Como o grafo é conexo, sabemos que todos os membros podem ser alcançados diretamente ou através de outros membros do grupo. Se usado o critério de facilidade de acesso às pessoas, quem deverá ser escolhido como líder do grupo?

A resposta a esta questão envolve o conceito de centro de um grafo, pois a melhor escolha para líder do grupo seria a pessoa que tivesse acesso mais fácil às outras pessoas do grupo, direta ou indiretamente.

Formalmente, defini-se antes o conceito de excentricidade de um vértice.

A excentricidade de um vértice v, denotada por E(v), é o valor da distância máxima entre v e u, ∀u∈V, em um grafo G=(V,E).
O centro de um grafo é igual ao subconjunto de vértices com excentricidade mínima.

Agora, considere que em um grupo de n pessoas tenha as suas possibilidades de comunicação descritas por um grafo não-direcionado conexo e acíclico T=(V,E). Dizemos que T é uma árvore. De acordo com o Teorema de Jordan, publicado em 1869, "O centro de uma árvore ou é formado por apenas um vértice ou por dois vértices vizinhos.".

Implemente uma função que dada uma árvore, retorne o seu vértice central. Caso haja empate, imprima o vértice com o menor índice lexicográfico.
*/