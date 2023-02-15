/* A inserção de elementos em uma fila é feita
no final (back), ja a remoção é feita
no inicio ()*/
/* -------------------------------------------------------------------- */

#include <iostream>
#include <list>

using namespace std;

int main() // pilhas
{
    list<int> fila; // ponteiro para fila
    int x;          // aux para leitura de dados
    int i;          // contador

    // lendo e inserindo elementos na fila
    for (int i = 0; i < 4; i++)
    {
        cin >> x;
        fila.push_back(x);
    }

    // removendo elementos da fila
    while (!fila.empty()) // enquanto a fila n estiver vazia
    {
        cout << *fila.begin() << " "; // mostra o primeiro elemento
        fila.pop_front();             // remove o primeiro nó da lista
    }

    return 0;
}