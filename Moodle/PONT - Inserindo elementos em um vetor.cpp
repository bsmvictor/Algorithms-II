#include <iostream>

using namespace std;

int main()
{
    int *vet = NULL; //ponteiro para o vetor
    int tam;         //tamanho do vetor
    int i;           //contador

    //alocando memoria
    vet = new int[tam];

    //tamanho do vetor
    cin >> tam;

    //inserindo dados
    for (i = 0; i < tam; i++)
    {
        cin >> vet[i];
    }

    //exibição do vetor
    for (i = 0; i < tam; i++)
    {
        cout << vet[i] << " ";
    }

    //liberando memoria
    delete[] vet;

    return 0;
}