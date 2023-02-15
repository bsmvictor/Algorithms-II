#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int *vet = NULL; //ponteiro para o vetor
    int tam;         //tamanho do vetor
    int i;           //contador
    float media = 0; //media dos elementos do vetor

    //tamanho do vetor
    cin >> tam;

    //alocando memoria
    vet = new int[tam];
    
    //inserindo dados
    for (i = 0; i < tam; i++)
    {
        cin >> vet[i];

        //calculo da Media
        media += vet[i];
    }

    //exibindo a media
    cout << fixed << setprecision(2);
    cout << media / tam * 1.0 << endl;

    //liberando memoria
    delete[] vet;

    return 0;
}