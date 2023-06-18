//Time Complexity: O(n^2)

#include <bits/stdc++.h>
using namespace std;

int findMin(bool *visited, int *weights, int n)
{
    int ans = INT_MAX;
    int index = -1;

    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            if(weights[i] < ans)
            {
                ans = weights[i];
                index = i;
            }
        }
    }

    return index;
}

void prim(bool *visited, int **adj, int *weights, int *parent, int n)
{
    for(int k=0; k<n; k++)
    {
        int index = findMin(visited, weights, n);
        visited[index] = true;

        for(int i=0; i<n; i++)
        {
            if(adj[index][i] > 0 && !visited[i])
            {
                if(adj[index][i] < weights[i])
                {
                    weights[i] = adj[index][i];
                    parent[i] = index;
                }
            }
        } 
    }

    for(int i=1; i<n; i++)
    {
        if(parent[i] > i)
        cout << i << " " << parent[i] << " " << weights[i] << endl;

        else
        cout << parent[i] << " " << i << " " << weights[i] << endl;
    }
}

int main() {
    // Write your code here
    int n, e;
    cin >> n >> e;

    int **adj = new int*[n];

    for(int i=0; i<n; i++)
    {
        adj[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            adj[i][j] = 0;
        }
    }

    for(int i=0; i<e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;

        adj[f][s] = w;
        adj[s][f] = w;
    }

    bool *visited = new bool[n];

    for(int i=0; i<n; i++)
    visited[i] = false;

    int *parent = new int[n];

    for(int i=0; i<n; i++)
    parent[i] = -1;

    int *weights = new int[n];
    weights[0] = 0;

    for(int i=1; i<n; i++)
    weights[i] = INT_MAX;

    prim(visited, adj, weights, parent, n);

    return 0;
}

//Optimized approach using priority queue
//Time Complexity: O((n+v)logn)

#include <bits/stdc++.h>
using namespace std;

void prim(bool *visited, int **adj, int *weights, int *parent, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,0});

    while(!pq.empty())
    {
        int weight = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();

        visited[vertex] = true;

        for(int i=0; i<n; i++)
        {
            if(adj[vertex][i] > 0 && !visited[i] && adj[vertex][i] < weights[i])
            {
                weights[i] = adj[vertex][i];
                parent[i] = vertex;
                pq.push({weights[i], i});
            }
        } 
    }

    for(int i=1; i<n; i++)
    {
        if(parent[i] > i)
        cout << i << " " << parent[i] << " " << weights[i] << endl;

        else
        cout << parent[i] << " " << i << " " << weights[i] << endl;
    }
}

int main() {
    // Write your code here
    int n, e;
    cin >> n >> e;

    int **adj = new int*[n];

    for(int i=0; i<n; i++)
    {
        adj[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            adj[i][j] = 0;
        }
    }

    for(int i=0; i<e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;

        adj[f][s] = w;
        adj[s][f] = w;
    }

    bool *visited = new bool[n];

    for(int i=0; i<n; i++)
    visited[i] = false;

    int *parent = new int[n];

    for(int i=0; i<n; i++)
    parent[i] = -1;

    int *weights = new int[n];
    weights[0] = 0;

    for(int i=1; i<n; i++)
    weights[i] = INT_MAX;

    prim(visited, adj, weights, parent, n);

    return 0;
}
