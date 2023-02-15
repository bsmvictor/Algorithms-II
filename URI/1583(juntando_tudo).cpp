#include <iostream>

using namespace std;

//struct de organização de dados
struct dado
{
    int k;      // chave
    int status; // 0-vazio, 1-ocupado, 2-removido
};

//divisao por k mod m
int h1(int k, int m)
{
    int resultado;

    resultado = k % m;

    if (resultado < 0)
        resultado += m;

    return resultado;
}

// função de auxilio para o double hashing
int h2(int k, int m)
{
    int res;

    res = 1 + (k % (m - 1));

    if (res < 0)
        res += m;

    return res;
}

// double hashing
int hash1(int k, int i, int m)
{
    return ((h1(k, m) + i * h2(k, m)) % m);
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
    int opcao;   //switch cases
    int j, i;    //auxiliares

    //Ler o tamanho da tabela
    cin >> m;

    //Inicializar a tabela
    for (j = 0; j < m; j++)
    {
        t[j].k = -1;
        t[j].status = 0;
    }

    //Ler as chaves
    cin >> opcao;

    while (opcao != 5)
    {
        if (opcao != 4)
            cin >> k;

        switch (opcao)
        {
        case 1: //inserir
            hash_insert(t, m, k);
            break;

        case 2: //pesquisar
            cout << hash_search(t, m, k) << endl;
            break;

        case 3: //remover
            hash_remove(t, m, k);
            break;

        case 4: //listar tabela
            for (int i = 0; i < m; i++)
            {
                if (i + 1 == m)
                    cout << t[i].k << endl;
                else
                    cout << t[i].k << " ";
            }
            break;
        }

        cin >> opcao;
    }

    return 0;
}
