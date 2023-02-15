#include <iostream>
#include <cmath>

using namespace std;

//Função recursiva
int pot(int numA, int numN)
{
    int an;

    //resultado de an caso n = 1
    if (numN == 0)
    {
        an = 1;
        return an;
    }

    //resultado de an caso n > 0
    else 
        return numA * pot(numA, numN - 1);

}

//Função principal
int main()
{
    //números inteiros
    int a, n;

    //Entrada dos valores de a e n
    cin >> a >> n;

    //chamada da função
    cout << pot(a, n) << endl;

    return 0;
}