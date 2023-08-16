#include<bits/stdc++.h>
using namespace std;

void greedy(int n, vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int minDiff = INT_MAX;

    for(int i=0; i<n-1; i++)
    {
        int diff = abs(arr[i] - arr[i+1]);
        minDiff = min(minDiff, diff);
    }

    cout << minDiff << endl;
}

int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        for(int i=0; i<n; i++)
        cin >> arr[i];

        greedy(n, arr);
    }
    return 0;
}
