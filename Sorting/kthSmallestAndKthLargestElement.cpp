#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int start, int end) {
    int pivot = arr[end]; 
    int i = start - 1;  

    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[end]);
    return i + 1;
}

int quickSelect(vector<int> &arr, int start, int end, int k) 
{
    if(start >= end) 
    return arr[start];

    int index = partition(arr, start, end);  

	if(index + 1== k)
	return arr[index]; 

	if(index + 1 == k)
	return arr[index]; 

	if(index + 1 > k)
    quickSelect(arr, start, index-1, k);  

	else
    quickSelect(arr, index+1, end, k);
}

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	vector<int> ans(2);
	ans[1] = quickSelect(arr, 0, n - 1, n-k+1);
	ans[0] = quickSelect(arr, 0, n - 1, k);
	return ans;
}
