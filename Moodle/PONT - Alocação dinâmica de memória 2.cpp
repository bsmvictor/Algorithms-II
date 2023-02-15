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

    dado *aluno = NULL; //ponteiro para o vetor
    int tam;            //tamanho do vetor
    int i;              //contador
    float Media;        //media dos alunos

    //tamanho do vetor
    cin >> tam;

    //alocando memoria
    aluno = new dado[tam];
    
    //inserindo dados
    for (i = 0; i < tam; i++)
    {
        //Entrada das notas dos alunos
        cin >> aluno[i].nota1 >> aluno[i].nota2 >> aluno[i].nota3 >> aluno[i].nota4;

        //media
        aluno[i].media = (aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3 + aluno[i].nota4) / 4.0;
    }

    //calculo da media
    for (i = 0; i < tam; i++)
    {
        Media += aluno[i].media;
    }

    //saida de dados
    cout << fixed << setprecision(2);
    cout << Media / tam * 1.0 << endl;

    //liberando memoria
    delete[] aluno;

    return 0;
}
