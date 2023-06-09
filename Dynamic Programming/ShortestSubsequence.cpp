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

#include <climits>

int helper(string s, string v, int m, int n, int **ans)
{
    if(m == 0)
    return 1005;

    if(n <= 0)
    return 1;

    if(ans[m][n] != -1)
    return ans[m][n];

    int i;

    for(i=0; i<n; i++)
    {
        if(s[0] == v[i])
        break;
    }

    if(i == n)
    return 1;

    int include = 1 + helper(s.substr(1), v.substr(i+1), m-1, n-i-1, ans);
    int exclude = helper(s.substr(1), v, m-1, n, ans);

    ans[m][n] = min(include, exclude);
    return ans[m][n];
}

int **allocate2DArray(int m, int n)
{
    int **ans = new int*[m+1];

    for(int i=0; i<=m; i++)
    ans[i] = new int[n+1];

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            ans[i][j] = -1;
        }
    }

    return ans;
}

int solve(string s, string v) {
    // Write your code here
    int m = s.length();
    int n = v.length();

    int **ans = allocate2DArray(m, n);

    return helper(s, v, m, n, ans);
}

//Using DP

#include <climits>

int helper(string s, string v, int m, int n, int **ans)
{
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int k;

            for(k=0; k<j; k++)
            {
                if(s[m-i] == v[n-(j-k)])
                break;
             }

            if(k == j)
            ans[i][j] = 1;

            else
            {
                int include = 1 + ans[i-1][j-k-1];
                int exclude = ans[i-1][j];

                ans[i][j] = min(include, exclude);
            }
        }
    }

    return ans[m][n];
}

int **allocate2DArray(int m, int n)
{
    int **ans = new int*[m+1];

    for(int i=0; i<=m; i++)
    ans[i] = new int[n+1];

    for(int j=0; j<=n; j++)
    ans[0][j] = 1005;

    for(int i=1; i<=m; i++)
    ans[i][0] = 1;

    return ans;
}

int solve(string s, string v) {
    // Write your code here
    int m = s.length();
    int n = v.length();

    int **ans = allocate2DArray(m, n);

    return helper(s, v, m, n, ans);
}
