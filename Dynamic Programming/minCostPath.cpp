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
