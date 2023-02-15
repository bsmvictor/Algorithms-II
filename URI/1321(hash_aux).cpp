#include <iostream>

using namespace std;

//função hash
int hash_aux(int k, int m)
{
    return k % m;
}

//função principal
int main()
{
    int k; //chave
    int m; //tamanho
    int r; //valor resultante

    //entrada de valores
    cin >> k >> m;

    //"flag" de k=0 e m=0
    while (k != 0 && m != 0)
    {
        //chamada de função
        r = hash_aux(k, m);

        //em caso de numeros negativos
        if (r < 0)
            r += m;

        //exibição do resultado
        cout << r << endl;

        //entrada de valores
        cin >> k >> m;
    }
    return 0;
}