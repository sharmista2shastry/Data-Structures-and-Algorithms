//Using Brute Force
//Time complexity: O(3^n), where n is the length of both the input strings

int helper(string s1, string s2, int len1, int len2)
{
	if(len1 == 0)
	{
		return len2;
	}

	if(len2 == 0)
	{
		return len1;
	}

	if(s1[0] == s2[0])
	return helper(s1.substr(1), s2.substr(1), len1-1, len2-1);

	int i = 1+ helper(s1.substr(1), s2, len1-1, len2);
	int d = 1+ helper(s1, s2.substr(1), len1, len2-1);
	int r = 1+ helper(s1.substr(1), s2.substr(1), len1-1, len2-1);

	return min(i, min(d, r));
}

int editDistance(string s1, string s2) {
	// Write your code here
	return helper(s1, s2, s1.length(), s2.length());
}

//Using Memoization
//Time Complexity: O(mn)

int helper(string s1, string s2, int m, int n, int **ans)
{
	if(m == 0 || n == 0)
	{
		return max(m, n);
	}

	if(ans[m][n] != -1)
	return ans[m][n];

	if(s1[0] == s2[0])
	return helper(s1.substr(1), s2.substr(1), m-1, n-1, ans);

	int i = 1+ helper(s1.substr(1), s2, m-1, n, ans);
	int d = 1+ helper(s1, s2.substr(1), m, n-1, ans);
	int r = 1+ helper(s1.substr(1), s2.substr(1), m-1, n-1, ans);

	ans[m][n] = min(i, min(d, r));
	return ans[m][n];
}

int **allocate2DArray(int m, int n)
{
	int **ans = new int*[m+1];

	for(int i=0; i<=m; i++)
	{
		ans[i] = new int[n+1];
	}

	for(int i=0; i<=m; i++)
	{
		for(int j=0; j<=n; j++)
		{
			ans[i][j] = -1;
		}
	}

	return ans;
}

int editDistance(string s1, string s2) {
	// Write your code here
	int m = s1.length(), n = s2.length();
	int **ans = allocate2DArray(m, n);

	return helper(s1, s2, m, n, ans);
}
