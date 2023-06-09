//Using Brute Force

#include <climits>

int helper(string s, string v, int m, int n)
{
    if(m == 0)
    return 1005;

    if(n <= 0)
    return 1;

    int i;

    for(i=0; i<n; i++)
    {
        if(s[0] == v[i])
        break;
    }

    if(i == n)
    return 1;

    int include = 1 + helper(s.substr(1), v.substr(i+1), m-1, n-i-1);
    int exclude = helper(s.substr(1), v, m-1, n);

    int res = min(include, exclude);
    return res;
}

int solve(string s, string v) {
    // Write your code here
    int m = s.length();
    int n = v.length();

    return helper(s, v, m, n);
}

//Using memoization


