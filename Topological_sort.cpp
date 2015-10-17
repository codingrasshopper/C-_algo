#include<iostream>
#include<list>
#include<stack>
using namespace std;

//Topological sort using DFS & adjacency list
class Graph {
	int V;
	list<int> *adj;
	void topologyUtil(int v, bool visited[], stack<int> &Stack);
	public:
		Graph(int V) {
			this->V = V;
			adj = new list<int>[V];
		}
		void addEdge(int v, int w){
			adj[v].push_back(w);
		}
		void topology();
};


void Graph::topologyUtil(int v, bool visited[], stack<int> &Stack){
	visited[v] = true;
	//cout << v << " ";
	list<int>::iterator it;
	for (it = adj[v].begin(); it != adj[v].end(); ++it) {
		if (!visited[*it])
			topologyUtil( *it, visited, Stack);
	}

	Stack.push(v);

}

void Graph::topology() {
	stack<int> Stack;
	bool *visited = new bool[V];
	for (int i=0; i<V; i++) {
		visited[i] = false;
	}
	for (int i=0; i<V; i++) {
		if (visited[i] == false)
			topologyUtil(i, visited, Stack);
	}
	
	while(Stack.empty() == false) {
		cout << Stack.top() << " ";
		Stack.pop();
	}
}

int main() {
	 Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
	g.topology();
	return 0;
}