/* ANOTAÇÕES
n: numero de vertices
m: numero de arestas

Complexidade de Tempo: O(m + n)
Complexidade de Espaço: O(n)

Pseudo-código:
   BFS(G,s)
      for vertice u em V - {s}
         u.cor = BRANCO
         u.d = oo
         u.pi = null
      u.cor = CINZA
      u.d = 0
      u.pi = null
      fila Q = ""
      ENFILEIRAR(Q, s)
      while(Q != " ")
         u = DESENFILEIRAR(Q)
         for cada v adj u
            if(v.cor == BRANCO)
               u.cor = CINZA
               u.d = u.d + 1
               u.pi = u
               ENFIEIRAR(Q, v)
         u.cor = PRETO


Problema do Menor Caminho em Grafos Não-Ponderados
   Instância: um grafo não ponderado qualquer, e um vértice origem (fonte)  s .
   Saída: um grafo que contenha o menor número de arestas que conecta à fonte  s .
   Esse problema pode ser resolvido através do Algoritmo de Busca em Largura, comumente referenciado por BFS (devido as suas iniciais em inglês: Breadth-First Search). A partir dos vértices de uma camada, a BFS explora todos os vértices ainda não alcançados da camada posterior, até que não hajam vértices a serem visitados. Para tanto, o algoritmo utilizada a estrutura de dados fila. Vejamos um exemplo de implementação da BFS, utilizando a estrutura de dados lista de adjacências.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

// cores dos vertices
#define BRANCO 0 // vertice nao descoberto
#define CINZA 1  // vertice descoberto
#define PRETO 2  // vertice fechado

int main()
{
   int n, m;
   cin >> n >> m;

   while (!cin.eof())
   {
      // alocando as estruturas auxiliares
      int *dist = new int[n + 1]; // distancia de todos os vertices em relacao a origem s
      int *pai = new int[n + 1];  // armazena o pai de cada vertice
      int *cor = new int[n + 1];  // armazena a cor de cada vertice

      // iniciando as estruturas auxiliares
      for (int i = 1; i <= n; i++)
      {
         dist[i] = 0;
         pai[i] = -1;
         cor[i] = BRANCO;
      }

      vector<int> *lista_adj = new vector<int>[n + 1];

      // leitura do grafo
      int u, v;
      for (int i = 0; i < m; i++)
      {
         cin >> u >> v; // lendo as arestas do grafo

         // evitando a leitura de vertices repetidos nas listas
         if (find(lista_adj[u].begin(), lista_adj[u].end(), v) != lista_adj[u].end())
         {
            continue;
         }

         // grafo nao-orientado
         lista_adj[u].push_back(v); // u -> v
         lista_adj[v].push_back(u); // v -> u
      }

      int s = 1;       // vertice origem
      queue<int> fila; // fila de vertices a serem explorados na BFS
      fila.push(s);
      cor[s] = CINZA;

      // para cada um que nao vai na festa, reduz o numero dos seus amigos
      while (!fila.empty())
      {
         int u = fila.front();
         fila.pop();
         cor[u] = PRETO;

         for (auto it = lista_adj[u].begin(); it != lista_adj[u].end(); it++)
         {
            // se o vertice ainda nao foi descoberto
            if (cor[*it] == BRANCO)
            {
               cor[*it] = CINZA;
               pai[*it] = u;
               dist[*it] = dist[u] + 1;
               fila.push(*it);
            }
         }
      }

      cout << "Distancias" << endl;
      for (int k = 1; k <= n; k++)
      {
         cout << "dist[" << k << "]: " << dist[k] << endl;
      }

      cout << "Pai" << endl;
      for (int k = 1; k <= n; k++)
      {
         cout << "pai[" << k << "]: " << pai[k] << endl;
      }
      cout << "*** *** ***" << endl;

      delete[] pai;
      delete[] cor;
      delete[] dist;

      cin >> n >> m;
   }

   return 0;
}