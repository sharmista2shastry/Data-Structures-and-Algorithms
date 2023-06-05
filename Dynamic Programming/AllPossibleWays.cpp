//Using memoization

#include<cmath>
#include <unordered_map>

int helper(int a, int b, int i, unordered_map <int, int> &ans)
{
	/*if(a < 0)
	return 0;*/

	if(a == 0)
	return 1;

	if(a - pow(i,b) < 0)
	return 0;

	if(ans.count(ans[a]) > 0)
	return ans[a];

	ans[a] = helper(a-pow(i,b), b, i+1, ans) + helper(a, b, i+1, ans);

	return ans[a];
}

int getAllWays(int a, int b) {
	// Write your code here
	unordered_map<int, int> ans;

	return helper(a, b, 1, ans);
}

