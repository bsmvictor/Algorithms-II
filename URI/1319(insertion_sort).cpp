#include <iostream>

using namespace std;

//função de Ordenação de Dados
int *insercaoDireta(int vetor[], int tamanho)
{
    int i, j; // contadores
    int chave;
    for (j = 1; j < tamanho; j++)
    {
        chave = vetor[j];
        i = j - 1;
        while ((i >= 0) && (vetor[i] < chave))
        {
            vetor[i + 1] = vetor[i];
            i = i - 1;
        }
        vetor[i + 1] = chave;
    }
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
    int *function = insercaoDireta(vet, i);

    //exibição do vetor em ordem decrescente
    for (int  j = 0; j < i; j++)
    {
        cout << vet[j] << " ";
    }

    cout << endl;

    return 0;
}