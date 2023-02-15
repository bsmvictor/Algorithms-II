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

vetor cria_vetor(ponto A, ponto B)
{
    vetor AB;
    AB.x = B.x - A.x;
    AB.y = B.y - A.y;
    return AB;
}

float escalar(vetor A, vetor B)
{
    float e;
    e = A.x * B.x + A.y * B.y;
    return e;
}

int main()
{
    float A, B, C;

    cin >> A.x >> A.y;
    cin >> B.x >> B.y;

    C = escalar(A, B);

    cout << C << endl;

    return 0;
}