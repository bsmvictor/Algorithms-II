#include <iostream>
#include <list>
#include <climits>

using namespace std;
struct no
{
    int v;       // vertice de destino
    int p;       // peso da aresta
    bool status; // status
};

// função de criar arestas
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

// função PRIM
void prim(list<no> adj[], int nVertices, int start)
{
    bool intree[100];
    long long int distance[100];
    int parent[100];
    int v;
    list<no>::iterator p;
    no result[100];

    long long int dist;
    int destino;
    int weight;

    int u = 0;
    int soma = 0;

    for (u = 0; u < nVertices; u++)
    {
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
    }

    distance[start] = 0;
    v = start;

    while (intree[v] == false)
    {
        intree[v] = true;
        for (p = adj[v].begin(); p != adj[v].end(); p++)
        {
            destino = p->v;
            weight = p->p;

            if (distance[destino] > weight && intree[destino] == false)
            {
                distance[destino] = weight;
                parent[destino] = v;
            }
        }

        v = 0;
        dist = INT_MAX;

        for (u = 0; u < nVertices; u++)
        {
            if (intree[u] == false && dist > distance[u])
            {
                if (result[u].status == false)
                {
                    result[u].v = parent[u];
                    result[u].p = distance[u];
                    result[u].status = true;
                }

                dist = distance[u];
                v = u;
            }
        }
    }

    for (u = 0; u < nVertices; u++)
    {
        if (u == 0)
            cout << "Arvore Geradora Minima:" << endl;
        if (u != start)
        {
            cout << result[u].v << " " << u << endl;
            soma += result[u].p;
        }
    }

    cout << "Custo: " << soma << endl;
}

int main()
{
    list<no> adj[10]; // lista de adjacencia
    int nVertices;    // numero de vertice do grafo
    int orientado;    // 1:orientado, 0:nao orientado
    int iVertice;     // vertice inicial da arvore
    int u, v;         // origem e destino da aresta
    int peso;         // peso da aresta

    cin >> nVertices >> orientado >> iVertice;

    cin >> u >> v >> peso;

    // inserindo arestas no grafo
    while (u != -1 && v != -1 && peso != -1)
    {
        cria_aresta(adj, u, v, peso, orientado);

        cin >> u >> v >> peso;
    }

    // chamando funcao prim
    prim(adj, nVertices, iVertice);

    return 0;
}
