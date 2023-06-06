//Using Basic Recursion

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

#include <climits>
#include <unordered_map>

using MemoizationTable = std::unordered_map<std::string, int>;

int countWaysToMakeChangeHelper(int denominations[], int numDenominations, int value, MemoizationTable& memo) {
    if (value == 0)
        return 1;

    if (value < 0)
        return 0;

    if (numDenominations == 0)
        return 0;

    std::string key = std::to_string(numDenominations) + "-" + std::to_string(value);
    if (memo.find(key) != memo.end())
        return memo[key];

    int include = countWaysToMakeChangeHelper(denominations, numDenominations, value - denominations[0], memo);
    int exclude = countWaysToMakeChangeHelper(denominations + 1, numDenominations - 1, value, memo);

    memo[key] = include + exclude;
    return memo[key];
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value) {
    MemoizationTable memo;
    return countWaysToMakeChangeHelper(denominations, numDenominations, value, memo);
}
