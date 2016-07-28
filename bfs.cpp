#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph{
    int V;
    list<int>*adj;
public:
    Graph(int V);
    void Add_edge(int v,int w);
    void Bfs(int s);
};
Graph::Graph(int V){
    this->V =V;
    adj = new list<int>[V];
}
void Graph::Add_edge(int v,int w){
    adj[v].push_back(w);
}
void Graph::Bfs(int s){
    bool visited[V];
    bool processed[V];
    int parent[V];

    for (int i=0;i<V;i++){
        visited[i] = processed[i] = false;
        parent[i]= -1;
    }

    queue<int> q;
    q.push(s);
    visited[s]=true;
    list<int>::iterator i;
    while(!q.empty()){
        s = q.front();
        cout<< s << " ";
        q.pop();

        for(i = adj[s].begin(); i!= adj[s].end(); ++i){
            if(!visited[*i]){
                visited[*i]=true;
                q.push(*i);
            }
        }
    }
}
int main(){
    Graph g(4);
    g.Add_edge(0, 1);
    g.Add_edge(0, 2);
    g.Add_edge(1, 2);
    g.Add_edge(2, 0);
    g.Add_edge(2, 3);
    g.Add_edge(3, 3);
    cout << "Following is the breadth first traversal starting from vertex 2 \n";
    g.Bfs(2);
    return 0;
}
