//Using Brute Force

#include<math.h>

void helper(int a, int b, int &count, int i)
{
	if(a == 0)
	{
		count++;
		return;
	}

	if(a - pow(i,b) < 0)
	return;

	helper(a-pow(i,b), b, count, i+1);
	helper(a, b, count, i+1);
}

int getAllWays(int a, int b) {
	// Write your code here
	int count = 0;
	helper(a, b, count, 1);

	return count;
}

//Using Memoization

