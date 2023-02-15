/* A inserção de elementos em uma pilha é feita
no inicio/top (front), ja a remoção é feita também
no inicio/top (front)*/
/* -------------------------------------------------------------------- */

#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> pilha; // ponteiro para pilha
    int x;           // aux para ler elementos inseridos na pilha
    int i;           // contador

    // lendo elementos e inserido-os na pilha
    for (int i = 0; i < 4; i++)
    {
        cin >> x;
        pilha.push_front(x);
    }

    // removendo elementos e mostrando-os
    while (!pilha.empty())
    {
        cout << *pilha.begin() << " ";
        pilha.pop_front();
    }

    return 0;
}