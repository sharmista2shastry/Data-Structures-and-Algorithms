#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
	// Write your code here. 
	sort(arr.begin(), arr.end());

	int start = 0, end = n - 1;
	vector<pair<int,int>> ans;

	while(start < end)
	{
		if(arr[start] + arr[end] == target)
		{
			ans.push_back({arr[start], arr[end]});
			start++;
			end--;
		}

		else if(arr[start] + arr[end] > target)
		end--;

		else if(arr[start] + arr[end] < target)
		start++;

		else
		{
			start++;
			end--;
		}
	}

	if(ans.size() == 0)
	ans.push_back({-1, -1});
	
	return ans;
}
