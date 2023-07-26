#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>> v;

  if(n == 0)
  return v;

  v.push_back({1});

  if(n == 1)
  return v;

  v.push_back({1,1});

  for(int i=2; i<n; i++)
  {
    vector<long long int> list; 
    list.push_back(1);

    for(int j=1; j<i; j++)
    {
      list.push_back(v[i-1][j-1] + v[i-1][j]);
    }

    list.push_back(1);
    v.push_back(list);
  }

  return v;
}
