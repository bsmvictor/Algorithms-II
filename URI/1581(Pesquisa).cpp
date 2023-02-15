#include <iostream>

using namespace std;

//struct de organização de dados
struct dado
{
    int k;      // chave
    int status; // 0:vazio, 1:ocupado
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

int main()
{
    dado T[100];   // tabela hash
    int K;         //chaves
    int M;         //tamanho da tabela
    int V;         //chave a ser verificada
    int j, i, aux; //aux

    //Ler o tamanho da tabela
    cin >> M;

    //Inicializar a tabela
    for (j = 0; j < M; j++)
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

    //chave a ser verificada
    cin >> V;

    //chamando a função
    aux = hash_search(T, M, V);

    //saida de dados da tabela
    if (aux != -1)
        cout << "Chave " << V << " encontrada na posicao " << aux << endl;

    else
        cout << "Chave " << V << " nao encontrada" << endl;

    return 0;
}