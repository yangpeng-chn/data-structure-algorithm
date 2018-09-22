#include <iostream>
#include <list>

using namespace std;

class Graph{
private:
    int m_v;
    list<int> *m_adj;
    bool *m_visited;
public:
    Graph(int v);
    void addEdge(int u, int w);
    void BFS(int s);
};

Graph::Graph(int v){
    m_v = v;
    m_adj = new list<int>[v];
}

void Graph::addEdge(int u, int w){
    m_adj[u].push_back(w);
}

void Graph::BFS(int s){
    m_visited = new bool[m_v];
    for(int i = 0; i < m_v; i++){
        m_visited[i] = false;
    }
    list <int> que;
    que.push_back(s);
    m_visited[s] = true;
    while(!que.empty()){
        int p = que.front();
        cout << p << " ";
        que.pop_front();
        list<int>::iterator i;
        for(i = m_adj[p].begin(); i != m_adj[p].end(); i++){
            if(!m_visited[*i]){
                que.push_back(*i);
                m_visited[*i] = true;
            }
        }
    }
}

int main (){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
    return 0;
}