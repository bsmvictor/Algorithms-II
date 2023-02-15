#include <iostream>
#include <iomanip>

using namespace std;

struct dado
{
    int nota1, nota2, nota3, nota4;
    float media;
};

int main()
{

    dado *notas = NULL; //ponteiro para o vetor
    int i;              //contador

    //alocando memoria
    notas = new dado;

    //inserindo dados
    cin >> notas->nota1 >> notas->nota2 >> notas->nota3 >> notas->nota4;

    //calculo da media
    notas->media = (notas->nota1 + notas->nota2 + notas->nota3 + notas->nota4) / 4.0;

    //saida de dados
    cout << fixed << setprecision(2);
    cout << notas->media;

    //liberando memoria
    delete[] notas;

    return 0;
}
