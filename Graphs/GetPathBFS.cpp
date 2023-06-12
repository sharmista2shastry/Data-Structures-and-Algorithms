#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

void getBFSPath(int n, int **edges, int sv, int ev, bool *visited)
{
    queue<int> q;
    unordered_map<int, int> mp;
    q.push(sv);
    visited[sv] = true;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(int i=0; i<n; i++)
        {
            if(i == front)
            continue;

            if(edges[front][i] == 1)
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                    mp[i] = front;
                }
            }
        }
    }

    if(mp.find(ev) == mp.end())
    return;

    int key = ev;

    while(key != sv)
    {
        cout << key << " ";
        key = mp[key];
    }

    cout << sv;
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
        int f, s;

        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int sv, ev;

    cin >> sv >> ev;

    bool *visited = new bool[n];

    for(int i=0; i<n; i++)
    visited[i] = false;

    getBFSPath(n, edges, sv, ev, visited);

    return 0;
}
