//Memoisation

#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;  // 10^9 + 7

int staircase(int n, unsigned long long *ans)
{
    if(n == 0)
    {
        return 1;
    }

    unsigned long long x = 0, y = 0, z = 0;

    if(ans[n] != -1)
    return ans[n];

    if(n-1 >=0 && ans[n-1] == -1)
    x = staircase(n-1, ans);

    else if(n-1 >= 0)
    x = ans[n-1];

    if(n-2 >= 0 && ans[n-2] == -1)
    y = staircase(n-2, ans);

    else if(n-2 >= 0)
    y = ans[n-2];

    if(n-3 >= 0 && ans[n-3] == -1)
    z = staircase(n-3, ans);

    else if(n-3 >= 0)
    z = ans[n-3];

    ans[n] = (x+y+z) % MOD;
    return ans[n];
}

int main(){
    // write your code here
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        unsigned long long *ans = new unsigned long long[n+1];

        for(int i=0; i<=n ; i++)
        ans[i] = -1;

        cout << staircase(n, ans) << endl;
    }
    return 0;
}

//Using DP

#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;  // 10^9 + 7

int staircase(int n, unsigned long long *ans)
{
    for(int i=1; i<=n; i++)
    {
        unsigned long long x = 0, y = 0, z = 0;

        if(i-1 >= 0)
        x = ans[i-1];

        if(i-2 >= 0)
        y = ans[i-2];

        if(i-3 >= 0)
        z = ans[i-3];

        ans[i] = (x + y + z) % MOD;
    }

    return ans[n];
}

int main(){
    // write your code here
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        unsigned long long *ans = new unsigned long long[n+1];

        ans[0] = 1;

        cout << staircase(n, ans) << endl;
    }
    return 0;
}
