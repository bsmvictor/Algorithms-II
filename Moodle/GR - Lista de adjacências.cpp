#include <iostream>
#include <list>

using namespace std;
struct no
{
    int v; // vertice de destino
    int p; // peso da aresta
};

void cria_aresta(list<no> adj[], int u, int v, int p, int orientado)
{
    no aux; // var aux para inserir arestas no grafo
    aux.v = v;
    aux.p = p;

    adj[u].push_back(aux);

    if (orientado == 0)
    {
        aux.v = u;
        adj[v].push_back(aux);
    }
}

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

    //inserindo o numero de vertices e se o grafo eh ou n orientado
    cin >> nVertices >> orientado;

    // inserindo arestas no grafo
    cin >> u >> v >> peso;

    while (u != -1 && v != -1 && peso != -1)
    {
        cria_aresta(adj, u, v, peso, orientado);
        cin >> u >> v >> peso;
    }

    // mostrando a lista de adjacencia
    for (i = 0; i < nVertices; i++)
        for (q = adj[i].begin(); q != adj[i].end(); q++)
            cout << i << " " << q->v << " " << q->p << endl;

    return 0;
}