#include <iostream>

using namespace std;

struct dado
{
    int k;      // chave
    int status; // 0:vazio, 1:ocupado
};

int hash_aux(int k, int m)
{
    return k % m;
}

int hash1(int k, int i, int m)
{
    return (hash_aux(k, m) + i) % m;
}

int hash_insert(dado t[], int m, int k)
{
    int i = 0;
    int j = 0;

    do
    {
        j = hash1(k, i, m);

        if (t[j].status != 1)
        {
            t[j].k = k;
            t[j].status = 1;
            return j;
        }
        else
            i++;
    } while (i != m);
    return -1;
}

int main()
{
    dado T[100]; // tabela hash
    int K;       //chaves
    int M;       //tamanho da tabela
    int j, i;    //aux

    //Ler o tamanho da tabela
    cin >> M;

    //Inicializar a tabela
    for ( j = 0; j < M; j++)
    {
        T[j].k = -1;
        T[j].status = 0;
    }

    //Ler as chaves
    cin >> K;

    //inserir chaves na tabela
    while (K != 0)
    {
        hash_insert(T, M, K);
        cin >> K;
    }

    //exibir a tabela
    for (i = 0; i < M; i++)
    {
        cout << T[i].k;

        if (i < M - 1)
            cout << " ";
    }

    cout << endl;

    return 0;
}
