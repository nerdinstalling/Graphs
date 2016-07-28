#include<iostream>
#include<queue>
#define MAXV 1000

using namespace std;

struct edgenode{
    int y;
    int weight;
    struct edgenode *next;
};
struct Graph{
    edgenode *edges[MAXV +1];
    int degree[MAXV+1];
    int nvertices;
    int nedges;
    bool directed;
};
void Initialize_graph(Graph *g,bool directed){
    g->nvertices = 0;
    g->nedges =0;
    g->directed = directed;
    for(int i=1;i<=MAXV;i++){
        g->degree[i] = 0;
        g->edges[i] = NULL;
    }
}
void Add_edge(Graph *g,int x,int y,int w,bool directed){
    edgenode *p;
    p = new edgenode;
    p->weight = w;
    p->y = y;
    p->next = g->edges[x];

    g->edges[x] = p;
    g->degree[x]++;

    if(directed == false)
        Add_edge(g,y,x,w,true);
    else
        g->nedges++;
}
void read_graph(Graph *g,bool directed){
    int M,x,y,w;
    Initialize_graph(g,directed);
    cin >> g->nvertices >> M;
    for(int i=1;i<=M;i++){
        cin >> x >> y >>w;
        Add_edge(g,x,y,w,directed);
    }

}
bool processed[MAXV+1];
bool discovered[MAXV+1];
int parent[MAXV+1];

void Initialize_search(Graph *g){
    for(int i=1;i<=MAXV;i++){
        processed[i]=discovered[i]=0;
        parent[i]=-1;
    }
}
bool finished = false;
void process_vertex_early(int v){
    cout<<v;
}
void process_vertex_late(int v){

}
void process_edge(int x,int y){
    if(parent[x] !=y){
        cout << "cycle from" << y << "to" << x <<endl;
        finished = true;
    }

}
void dfs(Graph *g,int v){
    edgenode *p;
    int y; // sucsessor vertex
    if (finished) return;

    discovered[v] = true;
    process_vertex_early(v);

    p = g->edges[v];
    while(p!= NULL){
        y = p->y;
        if(discovered[y] == false){
            parent[y] = v;
            process_edge(v,y);
            dfs(g,y);
        }
        else if ((!processed[y])||(g->directed)){
            process_edge(v,y);
        }
        if (finished) return;

        p = p->next;
    }
    process_vertex_late(v);
    processed[v]= true;
}
int main(){
    Graph g;
    read_graph(&g,true);
    dfs(&g,0);
}

