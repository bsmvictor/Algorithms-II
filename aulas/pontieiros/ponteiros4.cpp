#include <iostream>

using namespace std;

void soma(int x, int y, int *s)
{
    *s = x + y;
}

int main()
{
    int a = 2; // primeiro termo da soma
    int b = 3; // segundo termo da soma
    int c = 0; // a + b

    // calcular soma
    soma(a, b, &c); //&c recebe o valor de *s

    // mostrar soma
    cout << "soma = " << c << endl;
}