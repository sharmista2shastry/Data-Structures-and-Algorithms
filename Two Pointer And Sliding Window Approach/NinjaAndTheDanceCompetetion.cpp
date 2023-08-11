#include <bits/stdc++.h> 
int kDiffPairs(vector < int > & arr, int n, int k) {
    // Write your code here.
    unordered_set<int> s;
    unordered_map<int,int> mp;
    int count = 0;

    sort(arr.begin(), arr.end());
    
    for(int i=0; i<n; i++)
    {
        if(s.count(arr[i]-k) > 0 && mp[arr[i]-k] != arr[i])
        {
            count++;
            mp[arr[i]-k] = arr[i];
        }

        else
        mp[arr[i]] = INT_MIN;
        
        s.insert(arr[i]);
        
    }

    return count;
}
