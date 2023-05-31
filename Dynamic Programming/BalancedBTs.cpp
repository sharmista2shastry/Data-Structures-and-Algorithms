#include<bits/stdc++.h>

const int MOD = 1000000007;

int balancedBTs(int n)
{
    unsigned long long *dp = new unsigned long long[n+1];

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
    {
        unsigned long long count = 0;

        unsigned long long x = dp[i-1] * dp[i-2];
        unsigned long long y = dp[i-2] * dp[i-1];
        unsigned long long z = dp[i-1] * dp[i-1];

        count = (x + y + z) % MOD;
        dp[i] = count;
    }

    unsigned long long result = dp[n];
    delete[] dp;

    return result;
}
