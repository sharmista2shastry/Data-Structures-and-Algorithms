#include<iostream>         //Overall time complexity is (n+k)logk ====> O(n) assuming the value of k is very small
#include<queue>
using namespace std;

void kSortedArray(int arr[], int n, int k)
{
  priority_queue<int> pq;
  
  for(int i=0; i<k; i++).           //klogk 
  pq.push(arr[i]);
  
  int j=0;
  
  for(int i=k; i<n; i++)           //(n-k)logk
  {
    arr[j] = pq.top();
    pq.pop();
    pq.push(arr[i]);
  }
  
  while(!pq.empty())              //klogk
  {
    arr[j++] = pq.top();
    pq.pop();
  }
}
