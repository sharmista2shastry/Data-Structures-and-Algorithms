#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &arr, int x)
{
	// Write your code here.
	vector<int> res;
	int first = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
	int second = upper_bound(arr.begin(), arr.end(), x) - 1 - arr.begin();

	if(arr[first] != x)
	{
		res.push_back(-1);
		res.push_back(-1);
	}

	else
	{
		res.push_back(first);
		res.push_back(second);
	}

	return res;
}

