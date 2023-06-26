#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;

#define INF 100000000

vector<pair<int, int>> *LA;
int n;
int m;
vector<int> d;
vector<int> numArestas;

pair<int, int> dijkstra(int org, int dest)
{
   d.assign(n, INF);
   numArestas.assign(n, INF);

   d[org] = 0;
   numArestas[org] = 0;

   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
   heap.push(make_pair(0, org));

   while (!heap.empty())
   {
      pair<int, int> vertice = heap.top();
      heap.pop();

      int distancia = vertice.first;
      int u = vertice.second;

      if (u == dest)
         break;

      if (distancia > d[u])
         continue;

      for (int j = 0; j < (int)LA[u].size(); j++)
      {
         pair<int, int> vizinho = LA[u][j];
         int v = vizinho.first;
         int peso = vizinho.second;

         if (d[v] > d[u] + peso)
         {
            d[v] = d[u] + peso;
            numArestas[v] = numArestas[u] + 1;
            heap.push(make_pair(d[v], v));
         }
      }
   }

   return make_pair(d[dest], numArestas[dest]);
}

int main()
{
   cin >> n >> m;

   LA = new vector<pair<int, int>>[n];
   int u, v, p;
   for (int i = 0; i < m; i++)
   {
      cin >> u >> v;
      cin >> p;
      u--;
      v--;
      LA[u].push_back(make_pair(v, p));
   }

   pair<int, int> distancia = dijkstra(0, n - 1);

   cout << "Distancia em peso: " << distancia.first << endl;
   cout << "Distancia em numero de arestas: " << distancia.second << endl;

   return 0;
}