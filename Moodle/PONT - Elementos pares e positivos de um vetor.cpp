#include <iostream>

using namespace std;

int main()
{
    int *vet = NULL; //ponteiro para o vetor
    int tam;         //tamanho do vetor
    int i;           //contador
    int j = 0;       //numero de Elementos

    //tamanho do vetor
    cin >> tam;

    //alocando memoria
    vet = new int[tam];

    //inserindo dados
    for (i = 0; i < tam; i++)
    {
        cin >> vet[i];

        //contando numero de elementos pares e positivos
        if (vet[i] % 2 == 0 && vet[i] > 0)
            j++;
    }

    //exibindo maior elemento do vetor
    cout << j << endl;

    //liberando memoria
    delete[] vet;

    return 0;
}