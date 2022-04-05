
#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    void printAllPathsUtil(int v1, int v2, bool visited[], int path[], int index);

public:
    Graph(int V);
    bool pathExist;
    void addEdge(int v, int w);
    void printAllPaths(int v1, int v2);
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

void Graph::printAllPathsUtil(int v1, int v2, bool visited[], int path[], int index)
{

    visited[v1] = true;
    path[index] = v1;
    index++;

    if (v1 == v2)
    {
        int i;
        if (!pathExist)
            cout << "Following are the paths between " << path[0] << " and " << path[index - 1] << endl;
        pathExist = true;
        for (i = 0; i < index - 1; i++)
            cout << path[i] << "->";
        cout << path[i] << endl;
    }
    else
    {
        list<int>::iterator i;
        for (i = adj[v1].begin(); i != adj[v1].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, v2, visited, path, index);
    }

    index--;
    visited[v1] = false;
}

void Graph::printAllPaths(int v1, int v2)
{

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    int *path = new int[V];

    int index = 0;

    pathExist = false;

    printAllPathsUtil(v1, v2, visited, path, index);
}

int main()
{
    int V, A[2], start, end;
    cout << "Enter number of cities\n";
    cin >> V;
    Graph g(V);
    cout << "enter the starting city\n";
    cin >> start;
    cout << "enter the ending city\n";
    cin >> end;

    while (cin >> A[0] >> A[1])
    {
        if (A[0] < 0 || A[1] < 0 || A[0] >= V || A[1] >= V)
            cout << A[0] << "->" << A[1] << " refers to a non-existent node" << endl;
        else
            g.addEdge(A[0], A[1]);
    }
    /*
        g.addEdge(0, 1);
        g.addEdge(1, 0);
        g.addEdge(0, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 2);
        g.addEdge(3, 4);
        g.addEdge(4, 3);
        g.addEdge(1, 4);
        g.addEdge(4, 1);
        g.addEdge(1, 5);
        g.addEdge(5, 1);
        g.addEdge(5, 6);
        g.addEdge(6, 5);
        g.addEdge(3, 6);
        g.addEdge(6, 3);
    */
    g.printAllPaths(start, end);
    if (!g.pathExist)
    {
        cout << "There is no path exist between " << start << " and " << end;
    }
    return 0;
}