#include <iostream>
#include <list>

using namespace std;
struct no
{
    int v; // vertice de destino
    int p; // peso da aresta
};

int main()
{
    list<no> adj[10];     // lista de adjacencia
    list<no>::iterator q; // iterador para varrer a lista de adjacencia
    int u, v;             // origem e destino da aresta
    int peso;             // peso da aresta u-v
    int nVertices = 4;    // numero de vertice do grafo
    no aux;               // var aux para inserir arestas no grafo
    int i;                // contador
    int orientado = 0;    // 1:orientado, 0:nao orientado

    // inserindo arestas no grafo
    for (i = 0; i < 3; i++)
    {
        cin >> u >> v >> peso;
        aux.v = v;
        aux.p = peso;
        adj[u].push_back(aux);
        if (orientado == 0)
        {
            aux.v = u;
            adj[v].push_back(aux);
        }
    }

    // mostrando a lista de adjacencia
    cout << "Lista de adjacencia" << endl;
    for (i = 0; i < nVertices; i++)
        for (q = adj[i].begin(); q != adj[i].end(); q++)
            cout << i << " " << q->v << " " << q->p << endl;

    return 0;
}
