#include <iostream>
#include <cmath>

using namespace std;

struct dado
{
    int k;      // chave
    int status; // 0:vazio, 1:ocupado, 2:removido
};

int h1(int k, int m)
{
    int h; //resultado

    h = k % m; //resto da divisão de k por m

    if (h < 0) //em caso do resultado h ser menor que 0

        h = h + m; //soma-se m no resultado

    return h; //retorno do resultado h
}

int h2(int k, int m)
{
    int r = 0; //resultado

    r = 1 + k % (m - 1); //resto da divisão de k por (m - 1) + 1

    if (r < 0) //caso o resultado de r seja menor que 0

        r = r + m; //soma-se m ao resultado

    return r; //retorno do resultado r
}

//double hashing
int hash1(int k, int m, int i)
{
    return (h1(k, m) + i * h2(k, m)) % (m);
}

//busca de chave na tabela
int hash_search(dado t[], int m, int k)
{
    int i = 0; //contador
    int j;     //aux

    do
    {
        j = hash1(k, i, m);
        if (t[j].k == k)
            return j;
        else
            i++;
    } while (t[j].status != 0 && i < m);

    return -1;
}

//remoção de um elemento da tabela
int hash_remove(dado t[], int m, int k)
{
    int j;
    j = hash_search(t, m, k);
    if (j != -1)
    {
        t[j].status = 2;
        t[j].k = -1;
        return 0;
    }
    else
    {
        return -1;
    }
}

int main()
{
    dado t[100];  // tabela hash
    int k;        //chaves
    int m;        //tamanho da tabela
    int j, i = 0; //aux
    int vet[100];

    //Ler o tamanho da tabela
    cin >> m;

    //Inicializar a tabela
    for (j = 0; j < m; j++)
    {
        t[j].k = -1;
        t[j].status = 0;
    }

    //Ler as chaves
    cin >> k;

    //inserir chaves na tabela
    while (k != 0)
    {
        vet[j] = hash1(k, m, i);
        cin >> k;
        j++;
    }

    //chave a ser removida
    cin >> k;

    //chamando a função
    hash_remove(t, m, k);

   for (i = 0; i < m; i++)
    {
        if (i + 1 == m)
            cout << t[i].k << endl;
        else
            cout << t[i].k << " ";
    }

    return 0;
}
