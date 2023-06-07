//Using Memoization

int helper(int n, int x, int y, int *ans)
{
	if(n == 1 || n == x || n == y)
	return 1;

	if(n < 0)
	return 0;

	if(ans[n] != -1)
	return ans[n];

	int a, b, c;

	a = helper(n-1, x, y, ans) ^ 1;

	b = helper(n-x, x, y, ans) ^ 1;

	c = helper(n-y, x, y, ans) ^ 1;

	if(a == 1 || b == 1 || c == 1)
	{
		ans[n] = 1;
		return 1;
	}

	else
	{
		ans[n] = 0;
		return 0;
	}
}

string findWinner(int n, int x, int y)
{
	// Write your code here .
	int *ans = new int[n+1];

	for(int i=0; i<=n; i++)
	ans[i] = -1;

	int res = helper(n, x, y, ans);

	if(res == 1)
	return "Beerus";

	else
	return "Whis";
}

//Using DP

int helper(int n, int x, int y, int *ans)
{
	for(int i=2; i<=n; i++)
	{
		if(i == x || i== y)
		continue;

		int a, b, c;

		if(i-1 > 0)
		a = ans[i-1] ^ 1;

		else
		a = 0;

		if(i-x > 0)
		b = ans[i-x] ^ 1;

		else
		b = 0;

		if(i-y > 0)
		c = ans[i-y] ^ 1;

		else
		c = 0;

		if(a == 1 || b == 1 || c == 1)
		ans[i] = 1;

		else
		ans[i] = 0;
	}

	return ans[n];
}

string findWinner(int n, int x, int y)
{
	// Write your code here .
	int *ans = new int[n+1];

	ans[0] = 0;
	ans[1] = 1;
	ans[x] = 1;
	ans[y] = 1;

	int res = helper(n, x, y, ans);

	if(res == 1)
	return "Beerus";

	else
	return "Whis";
}
