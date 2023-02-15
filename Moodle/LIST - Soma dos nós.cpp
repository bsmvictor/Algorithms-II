#include <iostream>
#include <list>

using namespace std;

// função soma
int soma(list<int> lista)
{
    int Soma = 0; // soma dos valores da lista

    list<int>::iterator p; // varredura

    for (p = lista.begin(); p != lista.end(); p++)
        Soma = Soma + *p; // resultado da soma

    return Soma; //retorno do resultado da soma
}

int main()
{
    list<int> lista;       // ponteiro para a lista
    int resultado;         // resultado sa soma recebido pela função
    int x;                 // numero inseridos na lista

    // inserindo elementos na lista
    cin >> x;

    while (x != 0)
    {
        lista.push_front(x);
        cin >> x;
    }

    // chamada de função
    resultado = soma(lista);

    // exibindo a soma
    cout << resultado << endl;

    // Desalocando memoria utilizada pela lista
    while (!lista.empty())
        lista.pop_front();

    return 0;
}