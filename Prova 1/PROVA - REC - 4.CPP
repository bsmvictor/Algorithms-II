#include <iostream>

using namespace std;

//Função recursiva mdc
int mdc(int x, int y)
{
	//em caso de x = u
	if (x == y)
		return x;

	//em caso de x < y
	else if (x < y)
		return mdc(y, x);

	//nenhum dos casos anteriores satisfeitos
	else
		return mdc(x - y, y);
}

//Função principal
int main()
{
	int X, Y;	//valores a serem enviados a função
	int resultado;	//resultado da função

	//entrada das variaveis x e y
	cin >> X >> Y;

	//chamando a função recursiva
	resultado = mdc(X, Y);

	//exibindo resultado da função recursiva
	cout << resultado << endl;

	return 0;
}
