#include <iostream>

using namespace std;

//função de busca sequencial
int busca_sequencial(int vet[], int tam, int x)
{

    bool achou = false; //aux de busca
    int i = 0;          //contador

    while (achou == false && i < tam)
        achou = vet[i++] == x;

    if (achou)
        return (i - 1);

    else
        return -1;
}

int main()
{

    int i = 0;     //aux
    int vet[100];  //vetor
    int x;         //numero buscado
    int tam = 100; //numero de elementos
    int resultado; //resultado da busca

    //entrada de valores do vetor
    cin >> vet[i];
    while (vet[i] != -1)
    {
        i++;
        cin >> vet[i];
    }

    //busca por um valor no vetor
    cin >> x;

    //chamada de função
    resultado = busca_sequencial(vet, tam, x);

    //condicionais para a busca do valor no vetor
    if (resultado == -1)
        cout << x << " nao encontrado" << endl;

    else
        cout << x << " encontrado na posicao " << resultado << endl;

    return 0;
}