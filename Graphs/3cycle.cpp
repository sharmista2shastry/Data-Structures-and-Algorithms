#include <iostream>
using namespace std;

int main() {
    // Write your code here
    int n, m;
    cin >> n >> m;

    int **edges = new int*[n];

    for(int i=0; i<n; i++)
    {
        edges[i] = new int[n];
        for(int j=0; j<n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for(int i=0; i<m; i++)
    {
        int f,s;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int count = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j == i)
            continue;

            if(edges[i][j] == 1)
            {
                for(int k=0; k<n; k++)
                {
                    if(k == j || k == i)
                    continue;

                    if(edges[j][k] == 1)
                    {
                        if(edges[i][k] == 1)
                        count++;
                    }
                }
            }
        }
    }
    
    cout << count/6 << endl;
    return 0;
}
