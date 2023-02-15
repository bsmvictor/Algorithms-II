#include <iostream>
#include <list>

using namespace std;

int contar(list<int> lista)
{
    int conta = 0;
    list<int>::iterator p;

    for (p = lista.begin(); p != lista.end(); p++)
        conta++;

    return conta;
}
int main()
{
    list<int> lista;
    int N;         // inteiros a serem inseridos na lista
    int resultado; // aux para retorno da funcao

    // entrada de valores na tabela
    cin >> N;

    while (N != 0)
    {
        lista.push_back(N);
        cin >> N;
    }

    // chamando a funcao
    resultado = contar(lista);

    //exibindo numero de nos
    cout << resultado << endl;
}