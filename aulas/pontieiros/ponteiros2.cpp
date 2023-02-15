#include <iostream>

using namespace std;

struct dado
{
    int codigo;
    float preco;
};

int main()
{
    dado *produtos = NULL; // apontando para nada
    //alocando memoria
    produtos = new dado;

    //inserir dados
    produtos->codigo = 1;
    produtos->preco = 1.50;

    //mostrar Dados
    cout << "Codigo: " << produtos->codigo << endl;
    cout << "Preco: " << produtos->preco << endl;

    //liberar memoria
    delete produtos;

    return 0;
}