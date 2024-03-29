#include <iostream>
using namespace std;

void dfs(int n, int **edges, bool *visited, int sv)
{
    visited[sv] = true;

    for(int i=0; i<n; i++)
    {
        if(i == sv)
        continue;

        if(edges[sv][i] == 1 && !visited[i])
        dfs(n, edges, visited, i);
    }
}

int main() {
    // Write your code here
    int n, e;
    cin >> n >> e;

    int **edges = new int*[n];

    for(int i=0; i<n; i++)
    {
        edges[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for(int i=0; i<e; i++)
    {
        int f, s;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];

    for(int i=0; i<n; i++)
    visited[i] = false;

    dfs(n, edges, visited, 0);

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            cout <<"false";
            return 0;
        }
    }

    cout << "true";

    return 0;
}
