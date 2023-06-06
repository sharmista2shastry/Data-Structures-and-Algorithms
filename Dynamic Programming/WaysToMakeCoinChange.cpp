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

 unordered_map<string, int> mp;

int helper(int denominations[], int numDenominations, int value)
{
	if (value == 0)
        return 1;

    if (value < 0)
        return 0;

    if (numDenominations == 0)
        return 0;

	string key = to_string(numDenominations) + "-" + to_string(value);

	if(mp.find(key) != mp.end())
	return mp[key]; 

    int include = helper(denominations, numDenominations, value - denominations[0]);
    int exclude = helper(denominations + 1, numDenominations - 1, value);

    mp[key] = include + exclude;
	return mp[key];
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value) 
{
	return helper(denominations, numDenominations, value);
}
