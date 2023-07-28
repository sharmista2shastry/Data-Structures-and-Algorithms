Time Complexity: O(n)
Space Complexity: O(k)

#include<bits/stdc++.h>
using namespace std;

bool CheckSumPairs(int ar[], int n, int k, int m) {
	/*Write your code here. 
	*Don't write main().
	*Don't take input, it is passed as function argument.
	*Don't print output.
	*Taking input and printing output is handled automatically.
	*/ 
	unordered_map <int, int> mp;

	for(int i = 0; i< n; i++)
	{
		mp[ar[i] % k]++;
	}

	bool res = true;

	for(auto it = mp.begin(); it != mp.end(); it++)
	{
		if(it->first <= m)
		{
			if(mp.count(m - it->first) > 0 && mp[m - it->first] != mp[it->first])
			res = false;
			
			else if(mp.count(m - it->first) == 0)
			res = false;
		}

		else
		{
			if(mp.count((m + k) - it->first) > 0 && mp[(m + k) - it->first] != mp[it->first])
			res = false;

			else if(mp.count((m + k) - it->first) == 0)
			res = false;
		}
	}

	return res;
}
