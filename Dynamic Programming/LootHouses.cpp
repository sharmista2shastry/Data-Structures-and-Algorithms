//Using memoization

int helper(int *arr, int n, int *ans)
{
	if(n <= 0)
	return 0;

	if(ans[n] != -1)
	return ans[n];

	int x = helper(arr+2, n-2, ans) + arr[0];
	int y = helper(arr+1, n-1, ans);

	ans[n] = max(x,y);

	return ans[n];
}

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
	int *ans = new int[n+1];
	
	for(int i=0; i<=n; i++)
	{
		ans[i] = -1;
	}

	return helper(arr, n, ans);
}

//Using DP

int helper(int *arr, int n, int *ans)
{
	for(int i=1; i<=n; i++)
	{
		int x = ans[i-2] + arr[n-i];
		int y = ans[i-1];

		ans[i] = max(x,y);
	}

	return ans[n];
}

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
	int *ans = new int[n+1];
	
	ans[0] = 0;

	return helper(arr, n, ans);
}
