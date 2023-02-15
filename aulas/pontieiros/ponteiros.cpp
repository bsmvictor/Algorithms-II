// * variavel ponteiro.
// & variavel que recebe o valor do ponteiro.
#include <iostream>

using namespace std;

int main()
{
    int *vetor; //ponteiro para vetor
    int tam;    //tamanho desejado para vetor
    int i;      //contador

    //ler tamanho desejado para o vetore
    cin >> tam;

    //alocar memoria para o vetor
    vetor = new int[tam];

    //preencher vetor
    for (i = 0; i < tam; i++)
        cin >> vetor[i];

    //mostrar vetor
    for (i = 0; i < tam; i++)
        cout << vetor[i] << " ";
    cout << endl;

    //liberar memoria alocada para o vetor
    delete [] vetor;
    
    return 0;
}
