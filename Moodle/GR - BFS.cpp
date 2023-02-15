#include <iostream>
#include <list>

using namespace std;
struct no
{
    int v; // vertice de destino
    int p; // peso da aresta
};

//função de criar arestas
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

//função percurso em largura
void bfs(list<no> adj[], int nVertices, int s)
{
    int u;                // aux
    int state[100];       // estado do vertice
    int parente[100];     // parente
    list<int> Q;          // fila dos vertices
    list<no>::iterator p; // iterador para varrer a lista
    int ver;              // recebe vertice adjacente

    for (u = 0; u < nVertices; u++)
    {
        if (u != s)
        {
            state[u] = -1;   // nao visitado
            parente[u] = -1; // sem parentes
        }
    }

    state[s] = 0; // visitado
    parente[s] = -1;
    Q.push_back(s);

    while (!Q.empty())
    {
        u = Q.front();
        Q.pop_front();

        cout << u << endl;

        for (p = adj[u].begin(); p != adj[u].end(); p++)
        {
            ver = p->v;
            cout << u << " " << ver << endl;

            if (state[ver] == -1)
            {
                state[ver] = 0;   // visitado
                parente[ver] = u; // parente
                Q.push_back(ver);
            }
        }

        state[u] = 1; // processado
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

    //chamando função de percurso em largura
    bfs(adj, nVertices, orientado);

    return 0;
}