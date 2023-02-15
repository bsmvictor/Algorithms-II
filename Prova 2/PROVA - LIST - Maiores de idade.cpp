#include <iostream>
#include <list>

using namespace std;

int nMaiores(list<int> lista)
{
    list<int>::iterator p;
    int maiores = 0;

    for (p = lista.begin(); p != lista.end(); p++)
    {
        if (*p == 18 || *p > 18)
            maiores++;
    }

    return maiores;
}

int main()
{
    list<int> list; // ponteiro para fila
    int x;          // aux para leitura de dados
    int maiores;    // maiores de 18 anos

    // lendo e inserindo elementos na fila
    cin >> x;

    while (x != 0)
    {
        list.push_front(x);
        cin >> x;
    }

    // chamando a função
    maiores = nMaiores(list);

    // saida de dados
    cout << maiores << " pessoas com 18 anos ou mais" << endl;

    // removendo elementos da fila
    while (!list.empty()) // enquanto a fila n estiver vazia
        list.pop_front(); // remove o primeiro nó da lista

    return 0;
}