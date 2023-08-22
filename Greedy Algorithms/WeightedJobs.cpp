#include<bits/stdc++.h>
using namespace std;

struct Jobs{
    int start, finish,  profit;
};

bool cmp(Jobs a, Jobs b)
{
    return a.finish < b.finish;
}

int binarySearch(int i, Jobs arr[])
{
    int low = 0, high = i-1;

    while(low <= high)
    {
        int mid = (low + high)/2;

        if(arr[mid].finish <= arr[i].start)
        {
            if(arr[mid+1].finish <= arr[i].start)
            low = mid + 1;

            else
            return mid;
        }

        else
        high = mid - 1;
    }

    return -1;
}

int findMaxProfit(Jobs arr[], int n)
{
    int *dp = new int[n];
    dp[0] = arr[0].profit;

    for(int i=1; i<n; i++)
    {
        int incl = arr[i].profit;
        int l = binarySearch(i, arr);

        if(l != -1)
        incl += dp[l];

        dp[i] = max(incl, dp[i-1]);
    }

    int res = dp[n-1];
    delete [] dp;
    return res;
}

int main(){
    int n;
    cin >> n;

    Jobs arr[n];

    for(int i=0; i<n; i++)
    {
        cin >> arr[i].start >> arr[i].finish >> arr[i].profit;
    }

    sort(arr, arr+n, cmp);

    cout << findMaxProfit(arr, n) << endl;
    // write your code here
    return 0;
}
