#include <iostream>
#include <queue>
using namespace std;

 void print(int **edges, int n, bool *visited, int sv)
{
    queue<int> q;
    vector<int> res;

    q.push(sv);
    visited[sv] = true;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        cout << front << " ";

        for(int i=0; i<n; i++)
        {
            if(i == front)
            continue;

            if(edges[front][i] == 1)
            {
                if(visited[i])
                continue;

                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    // Write your code here
    int n;
    int e;

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
        int f, s;

        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];

    for(int i=0; i<n; i++)
    visited[i] = false;

   for(int i=0; i<n; i++)
   {
       if(visited[i] == false)
       print(edges, n, visited, i);
   }

    return 0;
}
