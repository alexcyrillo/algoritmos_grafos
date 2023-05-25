// https://www.beecrowd.com.br/judge/pt/problems/view/2323
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int verificarBalaceamento(vi *LA, bool &balanceado, int numAtual)
{
	int numFilhos = LA[numAtual].size(), pesoVertice = 1, filhoAtual = 0;

	if(numFilhos == 1 && balanceado)
		pesoVertice += verificarBalaceamento(LA, balanceado, LA[numAtual][0]);
	else if (numFilhos > 1 && balanceado)
	{
		int tamFilho[numFilhos] = {0};
		for (int i = 0; i < numFilhos; i++)
			tamFilho[i] += verificarBalaceamento(LA, balanceado, LA[numAtual][i]);
		while (balanceado == true && filhoAtual < numFilhos - 1)
		{
			if (tamFilho[filhoAtual] != tamFilho[filhoAtual + 1])
				balanceado = false;
			else
				filhoAtual++;
		}
	}
	return numFilhos;
}

int main()
{
	int numPecas, pecaRaiz, pecaSubR, pecaPendurada = 0;
	bool balanceado = true;
	
	cin >> numPecas;

	vi *LA = new vi[numPecas];
	
	// pega a peca raiz como a conectada a argola
	cin >> pecaRaiz >> pecaPendurada;

	for (int i = 0; i < numPecas - 1; i++)
	{
		cin >> pecaPendurada >> pecaSubR;
		LA[pecaSubR - 1].push_back(pecaPendurada - 1);
	}

	verificarBalaceamento(LA, balanceado, pecaRaiz - 1);

	cout << endl;

	if (balanceado)
		cout << "bem";
	else
		cout << "mal";

	return 0;
}