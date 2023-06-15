#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;

vector<pair<int, int>> *LA;
vector<int> d;
int n, m;

int dijkstra(int org)
{
   d.assign(n, 1);

   // a distance da origem "org" eh sempre zero
   d[org] = 1;

   // heap que auxilia na obtencao do vertice com maior prioridade, a cada iteracao
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

   // primeiro par inserido na heap: "org" com custo zero
   heap.push(make_pair(1, org));

   vector<bool> visitado;
   visitado.assign(n, false);

   // o algoritmo para quando a heap estiver vazia
   while (!heap.empty())
   {
      pair<int, int> vertice = heap.top();
      heap.pop();

      int distancia = vertice.first, u = vertice.second, custo;

      if (visitado[u]) // "u" jah foi explorado
         continue;

      visitado[u] = true;

      for (int j = 0; j < (int)LA[u].size(); j++)
      {
         pair<int, int> vizinho = LA[u][j];
         int v = vizinho.first, prob = vizinho.second;

         // tentativa de melhorar a estimativa de menor caminho da origem ao vertice v
         custo = d[u] * prob;
         if (custo < d[v])
         {
            d[v] = custo;
            heap.push(make_pair(d[v], v));
         }
      }
   }
}

int main()
{
   cin >> n >> m;

   LA = new vector<pair<int, int>>[n];
   int u, v, p;
   for (int i = 0; i < m; i++)
   {
      cin >> u >> v >> p;
      u--;
      v--;
      LA[u].push_back(make_pair(v, p));
   }

   dijkstra(1);

   

   return 0;
}