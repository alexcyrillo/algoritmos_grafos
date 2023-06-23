#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool *visitado;
vector <int> *LA;
int n, m;

void DFS(int u, vector<int> &pilha)
{
  visitado[u] = true;
  for(int i = 0; i < LA[u].size(); i++)
  {
    if(visitado[LA[u][i]] == false)
      DFS(LA[u][i], pilha);    
  }
  pilha.push_back(u);
}

bool teste(bool verif, vector<int> &pilha)
{
  int ePilha1, ePilha2;
  for(int i = 0; i < n; i++)
  {
    ePilha1 = pilha[i]; 
    ePilha2 = pilha[i + 1];
    for(int j = 0; j < LA[ePilha1].size(); j++)
    {
      if(!verif)
      {
        if(ePilha2 == LA[ePilha1][j])
        {
          verif = true;
          break;
        }
        else
        {
          verif = false;
        }
      }
    }
  }
  return verif;
}

void ordenar(int u)
{
  vector<int> pilha;
  for(int i = 0; i < n; i++)
    visitado[i] = false;
  DFS(0, pilha);
  reverse(pilha.begin(), pilha.end());
  bool verif;
  verif = teste(false, pilha);
  if(verif)
  {
    reverse(pilha.begin(), pilha.end());
    for(int i = 0; i < n; i++)
    {
      cout << pilha.back() << ' ';
      pilha.pop_back();
    }
  }
  else
    cout << -1;
  cout << endl;
  pilha.clear();
}
 
int main() {
  int a, b;
  do{
    cin >> n >> m;
    if(n != 0 && m != 0)
    {
      LA = new vector<int>[n];
      visitado = new bool[n];
      for(int i = 0; i < m; i++)
      {
        cin >> a >> b;
        if(a != 0 || b != 0)
          LA[a].push_back(b);
      }
      ordenar(0);
    }
  } while (n != 0 && m != 0);
  return 0;
}