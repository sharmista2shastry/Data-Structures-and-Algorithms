//Using Basic Recursion
//Time Complexity: O(2^n)

#include <climits>
#include <unordered_map>

int helper(int denominations[], int numDenominations, int value, unordered_map<int, int> &mp)
{
	if (value == 0)
        return 1;

    if (value < 0)
        return 0;

    if (numDenominations == 0)
        return 0;

    int include = helper(denominations, numDenominations, value - denominations[0], mp);
    int exclude = helper(denominations + 1, numDenominations - 1, value, mp);

    return include + exclude;
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value) 
{
    unordered_map <int, int> mp;
	return helper(denominations, numDenominations, value, mp);
}

//Using Memoization
//Time Complexity: O(numDenominations * value);

#include <climits>
#include <unordered_map>

int helper(int denominations[], int numDenominations, int value, int **ans)
{
	if (value == 0)
        return 1;

    if (value < 0)
        return 0;

    if (numDenominations == 0)
        return 0;

	if(ans[numDenominations][value] != -1)
	return ans[numDenominations][value];

    int include = helper(denominations, numDenominations, value - denominations[0], ans);
    int exclude = helper(denominations + 1, numDenominations - 1, value, ans);

    ans[numDenominations][value] = include + exclude;
	return ans[numDenominations][value];
}

int **allocate2DArray(int numDenominations, int value)
{
	int **ans = new int*[numDenominations + 1];

	for(int i=0; i<=numDenominations; i++)
	ans[i] = new int[value + 1];

	return ans;
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value) 
{
	int **ans = allocate2DArray(numDenominations, value);

	for(int i=0; i<=numDenominations; i++)
	{
		for(int j=0; j<=value; j++)
		{
			ans[i][j] = -1;
		}
	}

	return helper(denominations, numDenominations, value, ans);
}


//Using DP

#include <climits>
#include <unordered_map>

int helper(int denominations[], int numDenominations, int value, int **ans)
{
	for(int i=1; i<=numDenominations; i++)
	{
		for(int j=1; j<=value; j++)
		{
			int include = 0, exclude = 0;

			if(j - denominations[numDenominations - i] >= 0)
                    include = ans[i][j - denominations[numDenominations - i]];

                exclude = ans[i - 1][j];

                ans[i][j] = include + exclude;
		}
	}

	return ans[numDenominations][value];
}

int **allocate2DArray(int numDenominations, int value)
{
	int **ans = new int*[numDenominations + 1];

	for(int i=0; i<=numDenominations; i++)
	ans[i] = new int[value + 1];

	return ans;
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value) 
{
	int **ans = allocate2DArray(numDenominations, value);

	for(int i=0; i<=numDenominations; i++)
	ans[i][0] = 1;

	for(int j=0; j<=value; j++)
	ans[0][j] = 0;

	return helper(denominations, numDenominations, value, ans);
}

