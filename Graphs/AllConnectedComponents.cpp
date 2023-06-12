#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(int n, int **edges, int sv, bool *visited, vector<int> &res)
{
    visited[sv] = true;
    res.push_back(sv);

    for(int i=0; i<n; i++)
    {
        if(i == sv)
        continue;

        if(edges[sv][i] == 1 && !visited[i])
        dfs(n, edges, i, visited, res);
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
        edges[i][j] = 0;
    }

    for(int i=0; i<e; i++)
    {
        int f,s;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];

    for(int i=0; i<n; i++)
    visited[i] = false;

    vector<vector<int>> connComp;

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            vector<int> res;
            dfs(n, edges, i, visited, res);
            if(!res.empty())
            {
                sort(res.begin(), res.end());
                connComp.push_back(res);
            }
        }
    }

    for(int i=0; i<connComp.size(); i++)
    {
        for(int j=0; j<connComp[i].size(); j++)
        cout << connComp[i][j] << " ";

        cout << endl;
    }
}
