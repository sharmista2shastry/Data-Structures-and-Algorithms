//Using Memoization

int helper(int* arr, int n, int last, int *ans)
{
	if(n == 0)
	return 0;

	if(ans[n] != -1)
	return ans[n];

	if(arr[0] <= last)
	return helper(arr+1, n-1, last, ans);

	int x = 1 + helper(arr+1, n-1, arr[0], ans);
	int y = helper(arr+1, n-1, last, ans);

	ans[n] = max(x,y);
	return ans[n];
}

int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
	int *ans = new int[n+1];

	for(int i=0; i<=n; i++)
	ans[i] = -1;

	return helper(arr, n, -1, ans);
}
