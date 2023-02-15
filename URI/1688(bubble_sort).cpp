#include <iostream>

using namespace std;

//função de ordenação
int *bubbleSort(int vetor[], int tamanho)
{
    int i, j; //auxiliares
    int trab;
    bool troca;
    int limite;

    troca = true;
    limite = tamanho - 1;

    while (troca)
    {
        troca = false;
        for (i = 0; i < limite; i++)
            if (vetor[i] > vetor[i + 1])
            {
                trab = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = trab;
                j = i;
                troca = true;
            }
        limite = j;
    }
    return vetor;
}

//função principal
int main()
{

    int vet[100]; //vetor
    int i = 0;    //tamanho do vetor

    //entrada do primeiro valor do vetor
    cin >> vet[i];

    //entrada de valores do vetor enquanto diferente de 0
    while (vet[i] != 0)
    {
        i++;
        cin >> vet[i];
    }

    //chamada de função
    int *function = bubbleSort(vet, i);

    //exibição do vetor ordenado
    for (int j = 0; j <= i - 1; j++)
    {
        cout << vet[j] << " ";
    }

    cout << endl;

    return 0;
}