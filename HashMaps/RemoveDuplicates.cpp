#include<unordered_maps>
#include<vector>

vector<int> removeDuplicates(int *arr, int n)
{
  unordered_maps<int,bool> m;
  vector<int> v;
  for(int i=0; i<n; i++)
  {
    if(m.count(arr[i]) > 0)
      continue;
    
    arr[i] = true;
    v.push_back(arr[i]);
    
    return v;
  }
}
