#include<iostream>
#include<cmath>

using namespace std;

void quickSort(int vetor[], int tamanho, int i, int j)
{
	int trab, esq, dir, pivo;
	esq = i;
	dir = j;
	pivo = vetor[(int)round((esq + dir) / 2.0)];
	do
	{
		while (vetor[esq] < pivo)
			esq++;
		while (vetor[dir] > pivo)
			dir--;
		if (esq <= dir)
		{
			trab = vetor[esq];
			vetor[esq] = vetor[dir];
			vetor[dir] = trab;
			esq++;
			dir--;
		}
	}
	while (esq <= dir);
	if (dir - i >= 0)
		quickSort(vetor, tamanho, i, dir);
	if (j - esq >= 0)
		quickSort(vetor, tamanho, esq, j);
}

using namespace std;

int main()
{
    int i = 0;
    int vet[100];
    int j;
    int num;

    cin >> num;
    while(num != -1)
    {
        vet[i] = num;
        i++;
        cin >> num;
    }

    quickSort(vet, i, 0, i-1);

    for (j = 0; j < i; j++)

        cout << vet[j] << " ";

    return 0;
}