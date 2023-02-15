#include <iostream>

using namespace std;

//função hash
int hash_aux(int k, int m)
{
	int h;

	h = k % m;

	if (h < 0)
		h = h + m;

	return h;
}

//função hash
int hash1(int k, int i, int m)
{
	return (hash_aux(k, m) + i) % m;
}

//função principal
int main()
{
	int k; //key
	int m; //tamanho
	int vet[150];
	int j; //aux

	//entrada de dados
	cin >> k >> m;

	//organização de dados
	for (j = 0; j < m; j++)
	{
		vet[j] = hash1(k, j, m);
	}

	//exibição do resultado
	for (j = 0; j < m; j++)
	{
		cout << vet[j];

		if (j < m - 1)
			cout << " ";
	}

	cout << endl;
}