//Time complexity: O(nlogn)

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

//Alternate and slightly more efficient solution with O(nlogn) time complexity:

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
	// Write your code here. 
	unordered_map<int, int> mp;
	vector<pair<int,int>> ans;

	for(int i=0; i<n; i++)
	{
		if(mp.count(target - arr[i]) > 0 && mp[target-arr[i]] != -1)
		{
			ans.push_back({arr[i], target - arr[i]});
			mp[arr[i]] = -1;
		}

		else
		mp[arr[i]] = i;
	}

	if(ans.size() == 0)
	ans.push_back({-1, -1});

	return ans;
}
