//Using Brute Force
//Time complexity: O(3^(mn))

#include <climits>

int helper(int **input, int m, int n, int i, int j)
{
	if(i == m-1 && j == n-1)
	return input[m-1][n-1];

	int x = INT_MAX, y = INT_MAX, z = INT_MAX;

	if(i+1 < m)
	x = helper(input, m, n, i+1, j) + input[i][j];

	if(j+1 < n)
	y = helper(input, m, n, i, j+1) + input[i][j];

	if(i+1 < m && j+1 <n)
	z = helper(input, m, n, i + 1, j + 1) + input[i][j];

	return min(x, min(y,z));
}

int minCostPath(int **input, int m, int n)
{
	//Write your code here
	return helper(input, m, n, 0, 0);
}

//Using memoisation
//Time Complexity: O(m*n)
#include <climits>

int helper(int **input, int m, int n, int i, int j, int **ans)
{
	if(i == m-1 && j == n-1)
	return input[m-1][n-1];

	if(i >= m || j >= n)
	return INT_MAX;

	if(ans[i][j] != -1)
	return ans[i][j];

	int x = INT_MAX, y = INT_MAX, z = INT_MAX;

	x = helper(input, m, n, i+1, j, ans);
	y = helper(input, m, n, i, j+1, ans);
	z = helper(input, m, n, i + 1, j + 1, ans);

	ans[i][j] = min(x, min(y,z)) + input[i][j];
	return ans[i][j];
}

int** allocate2DArray(int m, int n) 
{
    int** arr = new int*[m];  // Allocate memory for m rows

    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];  // Allocate memory for each row
    }

    return arr;
}

int minCostPath(int **input, int m, int n)
{
	//Write your code here
	int **ans = allocate2DArray(m, n);

	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			ans[i][j] = -1;
		}
	}

	return helper(input, m, n, 0, 0, ans);
}

//Using DP

#include <climits>

int helper(int **input, int m, int n, int i, int j, int **ans)
{
	for(int j=n-2; j>=0; j--)
	ans[m-1][j] = ans[m-1][j+1] + input[m-1][j];

	for(int i=m-2; i>=0; i--)
	ans[i][n-1] = ans[i+1][n-1] + input[i][n-1];

	for(int i=m-2; i>=0; i--)
	{
		for(int j=n-2; j>=0; j--)
		{
			ans[i][j] = min(ans[i+1][j], min(ans[i+1][j+1], ans[i][j+1])) + input[i][j];
		}
	}

	return ans[0][0];
}

int** allocate2DArray(int m, int n) 
{
    int** arr = new int*[m];  // Allocate memory for m rows

    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];  // Allocate memory for each row
    }

    return arr;
}

int minCostPath(int **input, int m, int n)
{
	//Write your code here
	int **ans = allocate2DArray(m, n);

	ans[m-1][n-1] = input[m-1][n-1];

	return helper(input, m, n, 0, 0, ans);
}
