#include<iostream>
#include <list>

#define MAX 100
using namespace std;

void process_edge(int x,int y);

class Graph{
	int V;
	list<int> *adj;
public:
	Graph(int V);
	void initialize_search();
	void DFS(int start);
	void Add_edge(int v,int w);
};
Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}
void Graph::Add_edge(int v,int w){
	adj[v].push_back(w);
}
bool processed[MAX];
bool discovered[MAX];
int parent[MAX];

void Graph::initialize_search(){
	for(int i=0;i<MAX;i++){
		processed[i]=discovered[i]=false;
		parent[i]=-1;
	}
}
void Graph::DFS(int start){
	int v; //current vertex
	int y; //succesor vertex
	
    //	if (finished = true) return;
	
	discovered[start]= true;
	//process_vertex_early(start);
	cout<<start<<endl;
	list<int>::iterator it;
	it = adj[start].begin();
	
	while(it != adj[start].end()){
		y= *it;
		if(discovered[y]== false){
			parent[y]= start;
			
			//process_edge(start,y);
			DFS(y);
		}
		else if(!processed[y]){
			 process_edge(start,y);
		}
		//if (finshed) return;
		it++;
	}
	// process_vertex_late(start);
	processed[start]= true;
}
void process_edge(int x,int y){
	if (parent[x] != y){
		cout << "cycle from"<< y << "to" << x << endl;
	}
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
    g.initialize_search();
	g.DFS(2);
    return 0;
} 

































