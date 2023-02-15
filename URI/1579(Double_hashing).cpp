#include <iostream>

using namespace std;

//metodo da divisao
int h1(int k, int m)
{
	int h;

	h = k % m;

	if (h < 0)
		h = h + m;

	return h;
}

//sondagem linear
int h2(int k, int m)
{
    int r = 0;//resultado

	r = 1 + k % (m-1);

    if(r < 0)
        r = r + m;
    
    return r;
}

//double hashing
int hash1(int k, int m, int i)
{
    return (h1(k, m) + i * h2(k, m)) % (m);
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
		vet[j] = hash1(k, m, j);

        cout << vet[j];

		if (j < m - 1)
			cout << " ";
	}
	cout << endl;
}