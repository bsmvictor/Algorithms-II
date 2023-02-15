#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> lista;       // ponteiro de lista
    list<int> lista1;     // ponteiro de lista
    list<int> lista2;     // ponteiro de lista
    list<int>::iterator p; // iterador para lista
    list<int>::iterator o; // iterador para lista
    int aux1, aux2, aux;   // auxiliares

    cin >> aux;

    // Adicionar itens na lista
    while (aux != 0)
    {
        lista.push_back(aux);
        cin >> aux;
    }

    cin >> aux;

    while (aux != 0)
    {
        lista1.push_back(aux);
        cin >> aux;
    }

    // colocar lista em ordem crescente
    for (p = lista.begin(), o = lista1.begin(); p != lista.end(), p != lista.end(); p++, o++)
    {
        aux1 = *p;
        aux2 = *o;

        if (aux1 == aux2)
            lista2.push_back(aux1);
        else if (aux1 < aux2)
        {
            lista2.push_back(aux1);
            lista2.push_back(aux2);
        }
        else
        {
            lista2.push_back(aux2);
            lista2.push_back(aux1);
        }
    }

    // excluir elementos repetidos
    for (p = lista2.begin(), o = lista2.begin(); p != lista2.end(); p++, o++)
    {
        if (o == lista2.begin())
            o++;
        aux1 = *p;
        aux2 = *o;

        if (aux1 == aux2)
        {
            lista2.erase(o);
            p = lista2.begin();
            o = lista2.begin();
            p--;
            o--;
        }
    }

    // exibindo elementos da lista
    for (p = lista2.begin(); p != lista2.end(); p++)
    {
        aux = *p;
        cout << aux << " ";
    }
    cout << endl;

    // deslocar memoria
    while (!lista.empty() && !lista1.empty() && !lista2.empty())
    {
        lista.pop_front();
        lista1.pop_front();
        lista2.pop_front();
    }

    return 0;
}