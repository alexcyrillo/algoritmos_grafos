// https://www.beecrowd.com.br/judge/pt/custom-problems/view/3288
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

typedef pair<int, pair<int, int>> ii;
typedef vector<ii> vi;

void DFS(int u, vector<int> *lista_adj, bool *visitado)
{
   visitado[u] = true;

   for (auto it = lista_adj[u].begin(); it != lista_adj[u].end(); it++)
   {
      if (visitado[*it] == false)
      {
         DFS(*it, lista_adj, visitado);
      }
   }
}

vi ordenaPesos(int **MA, int numIntersec, int numRuas)
{
   vi lista;

   // cria a lista
   for (int i = 0; i < numIntersec - 1; i++)
      for (int j = i + 1; j < numIntersec; j++)
         if (MA[i][j] != 0)
            lista.push_back(make_pair(MA[i][j], make_pair(i, j)));

   sort(lista.begin(), lista.end());
   reverse(lista.begin(), lista.end());

   // cout << "------------------------------------------------";
   // for(int i = 0; i < lista.size(); i++)
   //    cout << lista[i].first << ' ' << lista[i].second.first << ' ' << lista[i].second.second << ' ' << endl;

   return lista;
}

int menorQtViagens(int **MA, int numRuas, int numIntersec, int trajetoIni, int trajetoFim, int numFunc)
{
   int numViagens = 0;
   vi lista = ordenaPesos(MA, numIntersec, numRuas);
   vector<int> *LA = new int[numIntersec];

   for (int i = 0; i < numRuas; i++)
   {
      // int u, v, p;
      // u = lista[i].second.first;
      // v = lista[i].second.second;
      // p = lista[i].first;

      bool visitado
      DFS(u, LA);
   }

   return numViagens;
}

int main()
{
   int numRuas, numIntersec, intersecU, intersecV, limiteP, numFunc, trajetoIni, trajetoFim, **MA;

   cin >> numIntersec >> numRuas;

   MA = new int *[numIntersec];
   for (int i = 0; i < numIntersec; i++)
      MA[i] = new int[numIntersec];

   for (int i = 0; i < numRuas; i++)
   {
      cin >> intersecU >> intersecV >> limiteP;

      MA[intersecU - 1][intersecV - 1] = limiteP;
      MA[intersecV - 1][intersecU - 1] = 0;
   }

   cin >> trajetoIni >> trajetoFim >> numFunc;

   cin >> intersecU >> intersecV;

   cout << menorQtViagens(MA, numRuas, numIntersec, trajetoIni, trajetoFim, numFunc);
   return 0;
}