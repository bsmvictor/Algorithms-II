#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Função recursiva
float function_raiz(float vx, float vx0, float ve)
{
    float raiz;

    raiz = pow(vx0, 2) - vx;
    if (raiz < 0)
        raiz = raiz * -1;

    //condição de parada
    if(raiz <= ve)
        return vx0;

    //chamada recursiva
    else
        return function_raiz(vx, (pow(vx0,2) + vx)/(2*vx0), ve);

}

//Função principal
int main()
{
    //números inteiros
    float x, x0, e;

    //Entrada dos valores de a e n
    cin >> x >> x0 >> e;

    //chamada da função
    cout << fixed << setprecision(2);
	cout << function_raiz(x, x0, e) << endl;

    return 0;
}