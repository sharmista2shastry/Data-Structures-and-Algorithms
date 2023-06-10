//Time Complexity: O(n*m)

int **allocate2DArray(int n, int m)
{
	int **ans = new int*[n];

	for(int i=0; i<n; i++)
	ans[i] = new int[m];

	return ans;
}

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	//Write your code here
	int **ans = allocate2DArray(n, m);

	int maxSquare = 0;

	for(int i=0; i<n; i++)
	{
		if(arr[i][0] == 0)
		ans[i][0] = 1;

		else
		ans[i][0] = 0;
		
		maxSquare = max(maxSquare, ans[i][0]);
	}

	for(int j=0; j<m; j++)
	{
		if(arr[0][j] == 0)
		ans[0][j] = 1;

		else
		ans[0][j] = 0;

		maxSquare = max(maxSquare, ans[0][j]);
	}

	for(int i=1; i<n; i++)
	{
		for(int j=1; j<m; j++)
		{
			if(arr[i][j] == 1)
			ans[i][j] = 0;

			else
			ans[i][j] = 1 + min(ans[i][j-1], min(ans[i-1][j-1], ans[i-1][j]));

			maxSquare = max(maxSquare, ans[i][j]);
		}
	}

	return maxSquare;
}
