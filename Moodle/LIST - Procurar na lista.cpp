#include <iostream>
#include <list>

using namespace std;

bool encontrar(list<float> lista, float x)
{
    list<float>::iterator p;

    for (p = lista.begin(); p != lista.end(); p++)
    {
        if (*p == x)
            return true;
    }
    return false;
}

int main()
{
    list<float> lista; // ponteiro para a lista
    int resultado;     // resultado sa soma recebido pela função
    int x;             // numero inseridos na lista
    int n;             // numero a ser pesquisado

    // inserindo elementos na lista
    cin >> x;

    while (x != 0)
    {
        lista.push_back(x);
        cin >> x;
    }

    // inserindo numero a ser buscado
    cin >> n;

    // chamada de função
    resultado = encontrar(lista, n);

    // exibindo
    if (resultado == true)
        cout << "Encontrado" << endl;

    else
        cout << "Nao encontrado" << endl;

    // Desalocando memoria utilizada pela lista
    while (!lista.empty())
        lista.pop_front();

    return 0;
}