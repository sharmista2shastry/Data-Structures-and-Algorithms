//Using Basic Recursion
// Time Complexity: O(n^n)

#include <climits>

int helper(int *arr, int start, int end, int res)
{
    if(start == end || start == end-1)
    return 0;

    for(int k=start+1; k<end; k++)
    {
        res = min(res, (helper(arr, start, k, res) + helper(arr, k, end, res) + (arr[start] * arr[k] * arr[end])));
    }

    return res;
}

int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    int res = INT_MAX;
    return helper(arr, 0, n, res);
}

//Using Memoization

#include <climits>
#include <unordered_map>

int helper(int *arr, int start, int end, int res, unordered_map<string, int> &mp)
{
    if(start == end || start == end-1)
    return 0;

    string key = to_string(start) + "-" + to_string(end);

    if(mp.find(key)!= mp.end())
    return mp[key];

    for(int k=start+1; k<end; k++)
    {
        res = min(res, (helper(arr, start, k, res, mp) + helper(arr, k, end, res, mp) + (arr[start] * arr[k] * arr[end])));
        mp[key] = res;
    }

    return res;
}

int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    unordered_map<string, int> mp;
    int res = INT_MAX;
    return helper(arr, 0, n, res, mp);
}
