#include <iostream>

using namespace std;

//função de busca binaria
int binaria(int vetor[], int tamanho, int x)
{

    bool achou = false; //aux de busca
    int i = 0;          // contador

    while (achou == false && i < tamanho)
        achou = vetor[i++] == x;

    //condicionais de acesso
    if (achou)
        cout << "Possui acesso" << endl;

    else
        cout << "Nao possui acesso" << endl;
}

int main()
{

    int i = 0;     //aux
    int vet[20];   //vetor
    int tam = 20;  //tamanho
    int x;         //numero buscado
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
    resultado = binaria(vet, tam, x);

    return 0;
}