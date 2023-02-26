#include<bits/stdc++.h>

using namespace std;

class Graph {
    int V;

    list<int>* adj;

    void topologicalSortUtil(int v, bool visited[],stack<int>& Stack);
    
    bool isCyclicUtil(int v, bool visited[], bool *rs);

public:
    Graph(int V);

    void addEdge(int v, int w);

    void topologicalSort();
    
    bool isCyclic(); 
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
   adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int>& Stack)
{
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    Stack.push(v);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;
 
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false; 
    return false;
}
void Graph::topologicalSort()
{
    stack<int> Stack;

    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    // Print contents of stack
    while (Stack.empty() == false) 
    {
        if (Stack.size() == 1)
            break;
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

bool Graph::isCyclic()
{

    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    for(int i = 0; i < V; i++)
        if ( !visited[i] && isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}

int main()
{
   int a,b;
    
    cin >> a >> b;
    Graph g(a + 1);
    for(int i = 0; i < a; i++)
    {
        int x,y;
        cin >> x >> y;
        g.addEdge(x, y);
    }
    if(g.isCyclic())
        cout << "-1" << endl;
    else
        g.topologicalSort();
    return 0;
}