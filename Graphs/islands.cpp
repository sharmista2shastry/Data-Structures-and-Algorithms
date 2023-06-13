#include <iostream>
using namespace std;

void island(int V, int **edges, bool *visited, int sv)
{
    visited[sv] = true;

    for(int i=0; i<V; i++)
    {
        if(i == sv)
        continue;

        if(edges[sv][i] == 1 && !visited[i])
        island(V, edges, visited, i);
    }
}

int main() {
    // Write your code here
    int V, E;
    cin >> V >> E;

    if(V == 0)
    {
        cout << "0";
        return 0;
    }

    int count = 0;

    int **edges = new int*[V];

    for(int i=0; i<V; i++)
    {
        edges[i] = new int[V];
        for(int j=0; j<V; j++)
        edges[i][j] = 0;
    }

    for(int i=0; i<E; i++)
    {
        int f, s;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[V];

    for(int i=0; i<V; i++)
    visited[i] = false;

    for(int i=0; i<V; i++)
    {
        if(visited[i] == false)
        {
            island(V, edges, visited, i);
            count++;
        }
    } 

    cout << count;
    return 0;
}
