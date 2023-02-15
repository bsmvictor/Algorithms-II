#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> lista;
    list<int> lista1;
    list<int>::iterator p;
    int es;    // itens de estoque
    int N;     // numero de operacoes
    int op;    // operacao
    int itens; // itens da lista
    int i = 0; // contador

    // inserindo elementos na lista
    cin >> N;

    while (i < N)
    {
        cin >> op;

        if (op == 1)
        {
            cin >> es;
            lista.push_back(es);
        }
        if (op == 2)
        {
            itens = *lista.begin();
            lista.pop_front();
            lista1.push_front(itens);
        }
        i++;
    }

    cout << "Estoque: ";
    for (p = lista.begin(); p != lista.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    cout << "Venda: ";
    for (p = lista1.begin(); p != lista1.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    return 0;
}