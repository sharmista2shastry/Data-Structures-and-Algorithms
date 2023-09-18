#include <bits/stdc++.h>

int minSwaps(vector<int> &arr)
{
	// Write your code here.
	int n = arr.size();
	vector<pair<int, int>> temp(n);

	for(int i=0; i<n; i++)
	{
		temp[i].first = arr[i];
		temp[i].second = i;
	}

	sort(temp.begin(), temp.end());

	int count = 0;
	int i = 0;

	while(i < n)
	{
		if(temp[i].first == arr[i] || temp[i].second == i)
		{
			i++;
			continue;
		}

		swap(temp[i].first, temp[temp[i].second].first);
		swap(temp[i].second, temp[temp[i].second].second);
		count++;
		if(temp[i].second != i)
		i--;
		i++;
	}

	return count;
}
