#include <iostream>

using namespace std;

struct dado
{
    int codigo;
    float preco;
};

int main()
{
    dado *produtos = NULL; //ponteiro para o vetor null =apontando para nada
    int tam;               //tamanho do vetor

    //lendo tamanho do vetor
    cin >> tam;

    //alocando memoria
    produtos = new dado[tam];

    //inserir dados
    for (int i = 0; i < tam; i++)
    {
        cin >> produtos[i].codigo;
        cin >> produtos[i].preco;
    }

    //mostrar Dados
    for (int i = 0; i < tam; i++)
    {
        cout << "Codigo: " << produtos[i].codigo << endl;
        cout << "Preco: " << produtos[i].preco << endl;
    }

    //liberar memoria
    delete produtos;

    return 0;
}