#include <bits/stdc++.h>
vector<int> relativeSorting(vector<int> &arr, vector<int> &brr, int n, int m)
{
    // Write your code here.
    map<int, int> mp;
    vector<int> res;

    for(int i=0; i<n; i++)
    mp[arr[i]]++;

    for(int i=0; i<m; i++)
    {
        if(mp.count(brr[i]) > 0)
        {
            while(mp[brr[i]]--)
            res.push_back(brr[i]);

            mp.erase(brr[i]);
        }
    }

    for(auto i: mp)
    {
        while(i.second--)
        res.push_back(i.first);
    }

    return res;
}
