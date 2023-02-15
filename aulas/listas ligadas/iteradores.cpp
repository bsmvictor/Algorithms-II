/* -Iteradores são ponteiros para cada elemento da lista
-para se varrer uma lista usamos:
    list<int>::iterator p;
        for(p=lista.begin();p!=lista.end();p++)
            cout << *p << endl;
/*----------------------------------------------------------------*/

#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> lista;       // ponteiro para a lista
    list<int>::iterator p; // iterador para a lista
    int soma = 0;          // soma de elementos da lista

    // inserindo elementos na lista
     for (p = lista.begin(); p != lista.end(); p++)
    lista.push_front(3);
    lista.push_front(1);
    lista.push_front(2);

    // mostrando elementos inseridos
    for (p = lista.begin(); p != lista.end(); p++)
        cout << *p << " ";
    cout << endl;

    // calculando e mostrando a soma dos elementos da lista
    for (p = lista.begin(); p != lista.end(); p++)
        soma += *p;

    cout << "soma = " << soma << endl;

    // Desalocando memoria utilizada pela lista
    while (!lista.empty())
        lista.pop_front();

    return 0;
}