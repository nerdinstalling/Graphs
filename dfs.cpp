#include <iostream>
#include <queue>
#include <list>

using namespace std;

class Graph{
    int V;
    list<int> *adj;
    void DFSutil(int v,bool visited[]);
public:
    Graph(int V);
    void Add_edge(int v,int w);
    void DFS(int v);
};
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
void Graph::Add_edge(int v,int w){
    adj[v].push_back(w);
}
void Graph::DFSutil(int v,bool visited[]){
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for(i= adj[v].begin(); i != adj[v].end();i++){
        if(!visited[*i])
            DFSutil(*i,visited);
    }
}
void Graph::DFS(int v){
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i]= false;
    }
    DFSutil(v,visited);
}
int main(){
    Graph g(4);
    g.Add_edge(0,1);
    g.Add_edge(0,2);
    g.Add_edge(1,2);
    g.Add_edge(2,0);
    g.Add_edge(2,3);
    g.Add_edge(3,3);

    cout << "THE FOLLOWING IS DEPTH FIRST TRAVERSAL STARTING FROM VERTEX 2" << endl;
    g.DFS(2);
    return 0;
}

