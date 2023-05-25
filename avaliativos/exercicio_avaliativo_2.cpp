// https://www.beecrowd.com.br/judge/pt/custom-problems/view/3288
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, pair<int, int>> ii;
typedef vector<ii> vi;

vi ordenaPesos(int **MA, int numIntersec, int numRuas)
{
   vi lista[numRuas]; 
   ii novoCaminho;

   for(int i = 0; i < numIntersec - 1; i++)
      for(int j = i + 1; j < numIntersec; j++)
         if(MA[i][j] != 0)
         {
            novoCaminho.first = MA[i][j];
            novoCaminho.second = make_pair(i, j);
            for(int k = 0; k < lista.size(); k++)
            {
               if()
            }
         }
   return lista;
}

int menorQtViagens(int **MA, int numRuas, int numIntersec, int trajetoIni, int trajetoFim, int numFunc)
{
   int numViagens = 0;

   ordenaPesos(MA, numIntersec, numRuas);


   return numViagens;
}

int main()
{
   int numRuas, numIntersec, intersecU, intersecV, limiteP, numFunc, trajetoIni, trajetoFim, **MA;

   cin >> numIntersec >> numRuas;

   *MA = new int[numIntersec];
   for (int i = 0; i < numIntersec; i++)
      MA[i] = new int[numIntersec];

   for(int i = 0; i < numRuas; i++)
   {
      cin >> intersecU >> intersecV >> limiteP;

      MA[intersecU - 1][intersecV - 1] == limiteP;
      MA[intersecV - 1][intersecU - 1] == 0;
      //MA[intersecV - 1][intersecU - 1] == limiteP;
   }

   cin >> intersecU >> intersecV;

   cout << menorQtViagens(MA, numRuas, numIntersec, trajetoIni, trajetoFim, numFunc);
   return 0;
}