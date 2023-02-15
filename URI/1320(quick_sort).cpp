#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct dados
{
    int codigo;     // código do produto
    int quantidade; // quantidade em estoque
    float preco;    // preço unitario
};

void quickSort(dados vetor[], int tamanho, int i, int j)
{
    int esq, dir, pivo;
    dados trab;
    esq = i;
    dir = j;
    pivo = vetor[(int)round((esq + dir) / 2.0)].codigo;
    do
    {
        while (vetor[esq].codigo < pivo)
            esq++;
        while (vetor[dir].codigo > pivo)
            dir--;
        if (esq <= dir)
        {
            trab = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = trab;
            esq++;
            dir--;
        }
    } while (esq <= dir);
    if (dir - i >= 0)
        quickSort(vetor, tamanho, i, dir);
    if (j - esq >= 0)
        quickSort(vetor, tamanho, esq, j);
}

int main()
{
    int N;          //número de produtos a serem cadastrados
    int i, j;       //auxiliares
    dados reg[100]; //vetor de struct

    //numero de produtos
    cin >> N;

    //cadastro dos produtos
    for (i = 0; i < N; i++)
    {
        cin >> reg[i].codigo;

        cin >> reg[i].quantidade;

        cin >> reg[i].preco;
    }

    //chamando a função
    quickSort(reg, N, 0, N - 1);

    //exibindo resultados
    for (j = 0; j < i; j++)
    {
        cout << "Codigo: " << reg[j].codigo << endl;

        cout << "Quantidade em estoque: " << reg[j].quantidade << endl;

        cout << fixed << setprecision(2);
        cout << "Preco unitario: R$ " << reg[j].preco << endl <<"\n";
    }

    return 0;
}