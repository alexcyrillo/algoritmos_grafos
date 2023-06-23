#include <iostream>
#include <vector>

using namespace std;

bool *visitado;
vector <int> *LA, pilha;
int n, m;

void DFS(int u)
{
  visitado[u] = true;
  for(int i = 0; i < LA[u].size(); i++)
  {
    if(visitado[LA[u][i]] == false)
      DFS(LA[u][i]);    
  }
  pilha.push_back(u);
}

void ordenar(int u)
{
  for(int i = 0; i < n; i++)
    visitado[i] = false;
  DFS(0);
  bool verif = false;
  int ePilha1, ePilha2;
  for(int i = n - 1; i > 0; i--)
  {
    ePilha1 = pilha[i]; 
    ePilha2 = pilha[i - 1];
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
  if(verif)
  {
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