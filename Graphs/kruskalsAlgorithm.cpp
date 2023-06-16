#include <iostream>
#include <algorithm>
using namespace std;

class edge
{
    public:
    int source;
    int dest;
    int weight;
};

bool compare(edge a, edge b)
{
    return a.weight < b.weight;
}

int findParent(int *parent, int index)
{
    while(parent[index] != index)
    {
        index = parent[index];
    }

    return index;
}

bool isSafe(edge input, int *parent, int &p1, int &p2)
{
    p1 = findParent(parent, input.source);
    p2 = findParent(parent, input.dest);

    if(p1 == p2)
    return false;

    else
    return true;
}

void kruskal(edge *input, edge *output, int n, int e)
{
    int *parent = new int[n];

    for(int i=0; i<n; i++)
    parent[i] = i;

    int count = 0;
    int i = 0;

    while(count != n-1)
    {
        int p1, p2;
        if(isSafe(input[i], parent, p1, p2))
        {
            output[count] = input[i];
            parent[p1] = p2;

            count++;
        }

        i++;
    }

    for(int i=0; i<count; i++)
    {
        if(output[i].source < output[i].dest)
        cout << output[i].source << " " << output[i].dest << " " << output[i].weight;

        else
        cout << output[i].dest << " " << output[i].source << " " << output[i].weight;

        cout << endl;
    }

    delete [] parent;
}

int main() {
    // Write your code here
    int n, e;
    cin >> n >> e;

    edge *input = new edge[e];
    edge *output = new edge[n-1];

    for(int i=0; i<e; i++)
    {
        int f,s,w;

        cin >> f >> s >> w;

        input[i].source = f;
        input[i].dest = s;
        input[i].weight = w;
    }

    sort(input, input+e, compare);

    kruskal(input, output, n, e);

    delete [] input;
    delete [] output;

    return 0;
}
