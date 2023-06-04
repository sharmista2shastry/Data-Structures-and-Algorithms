//Using Brute Force
//Time Complexity: O(2^n)

#include <climits>

int helper(int *weights, int *values, int n, int W)
{
	if(n == 0 || W == 0)
	return 0;

	if(weights[0] > W)
	return helper(weights+1, values+1, n-1, W);

	int x = helper(weights + 1, values + 1, n - 1, W-weights[0]) + values[0];
	int y = helper(weights+1, values+1, n-1, W);

	return max(x,y);
}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	return helper(weights, values, n, maxWeight);
}

//Using memoization
//Time Complexity: O(nw)

int helper(int *weights, int *values, int n, int W, int **ans)
{
	if(n == 0 || W == 0)
	return 0;

	if(ans[n][W] != -1)
	return ans[n][W];

	if(weights[0] > W)
	return helper(weights+1, values+1, n-1, W, ans);

	int x = helper(weights + 1, values + 1, n - 1, W-weights[0], ans) + values[0];
	int y = helper(weights+1, values+1, n-1, W, ans);

	ans[n][W]  = max(x,y);
	return ans[n][W];
}

int **allocate2DArray(int n, int w)
{
	int **ans = new int*[n+1];

	for(int i=0; i<=n; i++)
	ans[i] = new int[w+1];

	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<=w; j++)
		{
			ans[i][j] = -1;
		}
	}

	return ans;
}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	int **ans = allocate2DArray(n, maxWeight); 
	return helper(weights, values, n, maxWeight, ans);
}

//Using DP
int helper(int *weights, int *values, int n, int W, int **ans)
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=W; j++)
		{
			if(weights[n-i] > j)
			ans[i][j] = ans[i-1][j];

			else
			{
				int x = ans[i-1][j-weights[n-i]] + values[n-i];
				int y = ans[i-1][j];

				ans[i][j]  = max(x,y);
			}
		}
	}

	return ans[n][W];
}

int **allocate2DArray(int n, int w)
{
	int **ans = new int*[n+1];

	for(int i=0; i<=n; i++)
	ans[i] = new int[w+1];

	for(int i=0; i<=n; i++)
	ans[i][0] = 0;

	for(int j=0; j<=w; j++)
	ans[0][j] = 0;

	return ans;
}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	int **ans = allocate2DArray(n, maxWeight); 
	return helper(weights, values, n, maxWeight, ans);
}
