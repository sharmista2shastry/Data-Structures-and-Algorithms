#include <iostream>
#include <vector>
using namespace std;

vector<int> getPath(int n, int **edges, int sv, int ev, bool *visited)
{
    visited[sv] = true;

    if (sv == ev)
    {
        vector<int> path;
        path.push_back(ev);
        return path;
    }

    vector<int> path;

    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;

        if (edges[sv][i] == 1)
        {
            if (!visited[i])
            {
                path = getPath(n, edges, i, ev, visited);

                if(!path.empty())
                {
                    path.push_back(sv);
                    return path;
                }
            }
        }
    }

    return path;
}

int main() {
    // Write your code here
    int n, e;

    cin >> n >> e;

    if(n == 0 || e == 0)
    return 0;

    int **edges = new int*[n];

    for(int i=0; i<n; i++)
    {
        edges[i] = new int[n];
        for(int j=0; j<n; j++)
        edges[i][j] = 0;
    }

    for(int i=0; i<e; i++)
    {
        int f, s;

        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int sv , ev;

    cin >> sv >> ev;

    bool *visited = new bool[n];

    for(int i=0; i<n; i++)
    visited[i] = false;

    vector<int> path = getPath(n, edges, sv, ev, visited);

    for(int i=0; i<path.size(); i++)
    cout << path[i] << " ";

    delete [] visited;

    return 0;
}
