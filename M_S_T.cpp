#include <iostream>

#define MAXV    1000
#define MAXINT 1000000000
using namespace std;


struct edgenode{
    int y; // adjecency info
    int weight; // edge weight
    struct edgenode *next;
};
struct graph{
    edgenode *edges[MAXV];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
    bool directed;
};
void intitialize_graph(graph *g,bool directed){
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    for(int i = 1; i<=MAXV;i++){
        g->degree[i]=0;
        g->edges[i]= NULL;
    }
}
void Add_edge(graph *g,int x,int y,int w,bool directed){
    edgenode *p; // temporary pointer
    p = new edgenode; // allocate new node

    p->weight = w;
    p->y = y;
    p->next = g->edges[x];

    g->edges[x] = p;
    g->degree[x]++;

    if (directed == false)
        Add_edge(g,y,x,w,true);
    else
        g->nedges++;
}
void read_graph(graph *g,bool directed){
    int M,x,y,w;
    intitialize_graph(g,directed);
    cin>> g->nvertices >> M;
    for(int i=1;i<=M;i++){
        cin >> x >> y >> w;
        Add_edge(g,x,y,w,directed);
    }
}

void prim(graph *g,int start){
    int a=0;
    edgenode *p;
    bool intree[MAXV+1];
    int distance[MAXV+1];
    int parent[MAXV+1];
    int v;
    int w;
    int weight;
    int dist;
    for(int i=1;i<=g->nvertices;i++){
        intree[i] = false;
        distance[i]= MAXINT;
        parent[i] = -1;
    }
    distance[start] = 0;
    v = start;

    while(intree[v]==false){
        intree[v]= true;
        p = g->edges[v];
        while(p != NULL){
            w = p->y;
            weight = p->weight;
            if((distance[w]>weight)&&(intree[w]==false)){
                distance[w]=weight;
                parent[w]=v;
            }
        }

        v = 1;
        dist = MAXINT;
        for(int i=0; i<=g->nvertices;i++){
            if((intree[i] == false)&& (dist > distance[i])){
                dist = distance[i];
                v = i;
            }
        }

        a=a+dist;
    }
    cout << a;
}
int main(){
    graph g;
    read_graph(&g,true);
    prim(&g,1);
}
