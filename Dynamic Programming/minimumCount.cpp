//Brute Force

int minCount(int n)
{
	//Write your code here
	if(n == 0)
	return 0;

	if(n == 1)
	return 1;

	int min_count = n;

	int i=1;

	while(i*i <= n)
	{
		int count = 1 + minCount(n - (i*i));
		min_count = min(count, min_count);
		i++;
	}

	return min_count;
}

// Using memoisation

int helper(int n, int *ans)
{
	if(n == 0)
	return 0;

	if(n == 1)
	return 1;

	int min_count = n;

	if(ans[n] != -1)
	return ans[n];

	int i=1;

	while(i*i <= n)
	{
		int count;

		if(ans[n-(i*i)] != -1)
		count = 1+ ans[n-(i*i)];

		else
		count = 1 + helper(n - (i*i), ans);

		min_count = min(count, min_count);
		i++;
	}

	ans[n] = min_count;
	return min_count;
}

int minCount(int n)
{
	//Write your code here
	int *ans = new int[n+1];

	for(int i=0; i<=n; i++)
	ans[i] = -1;

	return helper(n, ans);
}

// Using DP

int helper(int n, int *ans)
{
	for(int num=2; num<=n; num++)
	{
		int i=1;
		int min_count = n;

		while(i * i <= num)
		{
			int count = 1 + ans[num - (i*i)];
			min_count = min(min_count, count);
			i++;
		}
		ans[num] = min_count;
	}

	return ans[n];
}

int minCount(int n)
{
	//Write your code here
	int *ans = new int[n+1];

	ans[0] = 0;
	ans[1] = 1;

	return helper(n, ans);
}
