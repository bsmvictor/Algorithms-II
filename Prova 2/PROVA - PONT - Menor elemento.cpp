#include <iostream>

using namespace std;

// função menor elemento
int menor(int *vetor, int N)
{
    int m = 100;

    for (int i = 0; i < N; i++)
    {
        if (vetor[i] < m)
        {
            m = vetor[i];
        }
    }

    return m;
}

int main()
{
    int *vet = NULL; // ponteiro para o vetor
    int N;           // tamanho do vetor
    int i;           // contador
    int result;      // resultado da funcao

    // tamanho do vetor
    cin >> N;

    // alocando memoria
    vet = new int[N];

    // inserindo elementos no vetor
    for (i = 0; i < N; i++)
    {
        cin >> vet[i];

        // chamando função
        result = menor(vet, N);
    }

    // exibindo menor elemento
    cout << result << endl;

    // liberando memoria
    delete[] vet;

    return 0;
}