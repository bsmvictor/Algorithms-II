#include <iostream>
#include <list>

using namespace std;

struct no
{
    int v; // vertice de destino
};

// função de criar arestas
void cria_aresta(list<no> adj[], int u, int v, int orientado)
{
    no aux; // var aux para inserir arestas no grafo
    aux.v = v;

    adj[u].push_back(aux);

    if (orientado == 0)
    {
        aux.v = u;
        adj[v].push_back(aux);
    }
}

void ordenacao_topologica(int f[100], int nVertices)
{
    int i, j;
    int aux;
    int a[100];
    a[0] = 0;

    for (i = 1; i <= nVertices; i++)
    {
        aux = f[i];
        j = i - 1;

        while (j >= 0 && f[j] < aux)
        {
            f[j + 1] = f[j];
            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j + 1] = i;
        f[j + 1] = aux;
    }

    for (i = 0; i < nVertices; i++)
    {
        if (i + 1 == nVertices)
            cout << a[i] << endl;
        else
            cout << a[i] << " ";
    }
}

void dfs_visit(list<no> adj[], int u, int color[100], int pi[100], int &time, int f[100])
{
    int d[100];
    int destino;
    list<no>::iterator p;

    color[u] = 2;
    time += 1;
    d[u] = time;

    for (p = adj[u].begin(); p != adj[u].end(); p++)
    {
        destino = p->v;
        if (color[destino] == 1)
        {
            pi[destino] = u;
            dfs_visit(adj, destino, color, pi, time, f);
        }
    }

    color[u] = 3;
    time += 1;
    f[u] = time;
}

void dfs(list<no> adj[], int nVertices)
{
    int color[100];
    int pi[100];
    int time;
    int f[100];

    for (int u = 0; u < nVertices; u++)
    {
        color[u] = 1;
        pi[u] = -1;
    }

    time = 0;

    for (int u = 0; u < nVertices; u++)
    {
        if (color[u] == 1)
            dfs_visit(adj, u, color, pi, time, f);
    }

    ordenacao_topologica(f, nVertices);
}

int main()
{
    list<no> adj[10]; // lista de adjacencia
    int nVertices;    // numero de vertice do grafo
    int orientado;    // 1:orientado, 0:nao orientado
    int u, v;         // origem e destino da aresta

    // entrando com o numero de vertices e orientacao
    cin >> nVertices >> orientado;

    // inserindo arestas no grafo
    cin >> u >> v;

    while (u != -1 && v != -1)
    {
        cria_aresta(adj, u, v, orientado);
        cin >> u >> v;
    }

    // chamando função dfs
    dfs(adj, nVertices);

    return 0;
}
