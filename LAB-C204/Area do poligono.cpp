#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct ponto
{
	float x;
	float y;
};
typedef ponto vetor;

struct reta
{
	ponto A;
	ponto B;
};
typedef reta segmento;

vetor cria_vetor(ponto A, ponto B)
{
	vetor AB;
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	return AB;
}

float vetorial(vetor A, vetor B)
{
	float v;
	v = A.x * B.y - A.y * B.x;
	return v;
}

float escalar(vetor A, vetor B)
{
	float e;
	e = A.x * B.x + A.y * B.y;
	return e;
}

float area_triangulo(ponto A, ponto B, ponto C)
{
	vetor AB;
	vetor AC;
	float area;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	area = vetorial(AB, AC);
	return area;
}

// Os pontos devem estar ordenados radialmente
// O poligono deve ser convexo
// Retorna a area do poligono
float area_poligono(ponto v[], int n)
{
	float area = 0;
	for (int i = 0; i < n-2; i++)
	{
		area += area_triangulo(v[0], v[i + 1], v[i + 2]);
	}
	return area;
}

int main()
{
	int n;
	ponto p[10];
	float area;

	//entrando com o numero de casas
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> p[i].x >> p[i].y;
	}
	area = area_poligono(p, n);
	cout << fixed << setprecision(2);
	cout << area << " m" << endl;

	return 0;
}