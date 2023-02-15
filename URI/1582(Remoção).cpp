#include <iostream>

using namespace std;

//struct de organização de dados
struct dado
{
    int k;      // chave
    int status; // 0-vazio, 1-ocupado, 2-removido
};

//divisao por k mod m
int hash_aux(int k, int m)
{
    int resultado;

    resultado = k % m;

    if (resultado < 0)
        resultado += m;

    return resultado;
}

//sondagem linear junto da função hash_aux
int hash1(int k, int i, int m)
{
    int result = 0;

    result = hash_aux(k, m);

    result = hash_aux(k + i, m);

    return result;
}

//retorno da posição da chave ou -1
int hash_insert(dado t[], int m, int k)
{
    int i = 0;

    do
    {
        int j = hash1(k, i, m);

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
    dado t[100]; // tabela hash
    int k;       //chaves
    int m;       //tamanho da tabela
    int j, i;    //aux

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
        hash_insert(t, m, k);
        cin >> k;
    }

    //chave a ser removida
    cin >> k;

    //chamando a função
    hash_remove(t, m, k);

    //saida de dados da tabela
    for (i = 0; i < m; i++)
    {
        if (i + 1 == m)
            cout << t[i].k << endl;
        else
            cout << t[i].k << " ";
    }

    return 0;
}
