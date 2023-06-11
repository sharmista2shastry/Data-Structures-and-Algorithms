#include <iostream>
using namespace std;

void print(int edges, int n, int sv, int *visited) //sv = starting vertex
{
  cout << sv << endl;
  visited[sv] = true;
  
  for(int i=0; i<n; i++)
  { 
    if(i == sv)
      continue;
    
    if(edges[sv][i] == 1)
    {
      if(visited[i])
        continue;
      print(edges, n, i);
    }
  }
}

int main()
{
  int n;//Number of vertices
  int e; //Number of edges
  
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
  
  bool *visited = new int[n];
  
  for(int i=0; i<n; i++)
    visited[i] = false;
  
  print(edges, n, 0, visited);
  
  return 0;
}
  
