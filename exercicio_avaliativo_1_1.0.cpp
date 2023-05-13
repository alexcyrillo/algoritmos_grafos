//https://www.beecrowd.com.br/judge/pt/problems/view/2323
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int verificarBalaceamento(vi *LA, bool &balanceado, int numAtual)
{
	int numFilhos = LA[numAtual].size(), pesoVertice = 1, filhoAtual = 0;

	if (numFilhos > 0 && balanceado == true)
	{
		int tamFilho[numFilhos];
		for (int i = 0; i < numFilhos; i++)
		{
			tamFilho[i] = verificarBalaceamento(LA, balanceado, LA[numAtual][i]);
			pesoVertice += tamFilho[i];
		}
		while (balanceado == true && (filhoAtual < (numFilhos - 1) && numFilhos > 1))
		{
			if (tamFilho[filhoAtual] != tamFilho[filhoAtual + 1])
				balanceado = false;
			else
				filhoAtual++;
		}
	}

	return pesoVertice;
}

int main()
{
	int numPecas, pecaRaiz, pecaSubR, pecaPendurada = 0;
	bool balanceado = true;
	vi *LA;

	cin >> numPecas;

	LA = new vi[numPecas];

	//pega a peca raiz como a conectada a argola
	cin >> pecaRaiz >> pecaPendurada;

	for (int i = 0; i < numPecas - 1; i++)
	{
		cin >> pecaPendurada >> pecaSubR;
		LA[pecaSubR - 1].push_back(pecaPendurada - 1);
	}

	balanceado, numPecas = verificarBalaceamento(LA, balanceado, pecaRaiz - 1);
	
	cout << endl;

	if (balanceado)
		cout << "bem";
	else
		cout << "mal";

	return 0;
}