//Time Complexity: O((n + e)logn)

#include <bits/stdc++.h>>
using namespace std;

void dijkstra(bool *visited, int *dist, int **adj, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while(!pq.empty())
    {
        int distance = pq.top().first;
        int vertex = pq.top().second;
        visited[vertex] = true;

        pq.pop();

        for(int i=0; i<n; i++)
        {
            if(adj[vertex][i] > 0 && !visited[i] && dist[vertex] + adj[vertex][i] < dist[i])
            {
                dist[i] = dist[vertex] + adj[vertex][i];
                pq.push({dist[i], i});
            }
        }
    }

    for(int i=0; i<n; i++)
    cout << i << " " << dist[i] << endl;
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
        adj[s][f]  = w;
    }

    bool *visited = new bool[n];

    for(int i=0; i<n; i++)
    visited[i] = false;

    int *dist = new int[n];
    dist[0] = 0;
 
    for(int i=1; i<n; i++)
    dist[i] = INT_MAX;

    dijkstra(visited, dist, adj, n);

    return 0;
}
