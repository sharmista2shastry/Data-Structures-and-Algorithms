//Time Complexity: O(n^2 + e), where n is number of vertices and e is number of edges

#include <iostream>
using namespace std;

bool hasPath(int n, int **edges, int sv, bool *visited, int end)
{
    if(sv == end)
    return true;

    visited[sv] = true;

    for(int i=0; i<n; i++)
    {
        if(i == sv)
        continue;

        if(edges[sv][i] == 1)
        {
            if(!visited[i])
            {
                if(hasPath(n, edges, i, visited, end))
                return true;

                visited[i] = false;
            }
        }
    }

    return false;
}

int main() {
    // Write your code here
    int n, e;

    cin >> n >> e;

    if(n == 0 || e == 0)
    {
        cout << "false";
        return 0;
    }

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

    int start, end;

    cin >> start >> end;

    bool *visited = new bool[n];

    for(int i=0; i<n; i++)
    visited[i] = false;

    if(hasPath(n, edges, start, visited, end))
    cout << "true";

    else
    cout << "false";

    return 0;
}
