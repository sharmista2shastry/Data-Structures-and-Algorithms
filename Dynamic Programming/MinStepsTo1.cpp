//Brute Force Approach

#include<climits>

int helper(int n)
{
	if(n <= 1)
	return 1;

	int x = INT_MAX, y = INT_MAX, z = INT_MAX;

	x = helper(n-1);

	if(n % 3 == 0)
	y = helper(n/3);

	if(n % 2 == 0)
	z = helper(n/2);

	return min(x, min(y, z)) + 1;
}

int countMinStepsToOne(int n)
{
	//Write your code here
	if(n == 1)
	return 0;

	return helper(n) - 1;
}

// Using Memoization 

#include<climits>

int helper(int n, int *ans)
{
	if(n <= 1 || n == 2 || n == 3)
	return 1;

	int x = INT_MAX, y = INT_MAX, z = INT_MAX;

	if(ans[n] != -1)
	return ans[n];

	if(ans[n-1] == -1)
	x = helper(n-1, ans);

	else
	x = ans[n-1];

	if(n % 3 == 0 && ans[n/3] == -1)
	y = helper(n/3, ans);

	else if(n % 3 == 0)
	y = ans[n/3];

	if(n % 2 == 0 && ans[n/2] == -1)
	z = helper(n/2, ans);

	else if(n % 2 == 0)
	z = ans[n/2];

	ans[n] = min(x, min(y, z)) + 1;

	return ans[n];
}

int countMinStepsToOne(int n)
{
	//Write your code here
	if(n == 1)
	return 0;

	int *ans = new int[n+1];

	for(int i=0; i<=n ; i++)
	{
		ans[i] = -1;
	}

	return helper(n, ans);
}

// Using DP

#include <climits>

int helper(int n, int *arr)
{
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;

	for(int i=4; i<=n; i++)
	{
		int x, y = INT_MAX, z = INT_MAX;
		
		x = arr[i-1];
		
		if(i % 3 == 0)
		y = arr[i/3];

		if(i % 2 == 0)
		z = arr[i/2];

		arr[i] = min(x, min(y, z)) + 1;
	}

	return arr[n];
}

int countStepsToOne(int n)
{
	//Write your code here
	if(n == 1)
	return 0;

	int *arr = new int[n+1];
	return helper(n, arr);
}
