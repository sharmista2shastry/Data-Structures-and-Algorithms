#include <bits/stdc++.h>
using namespace std;

bool compare(pair<long, long> &a, pair<long, long> &b)
{
    return a.first < b.first;
}

bool checkOverlappingIntervals(long* start, long* end, int n)
{
    //Write your code here 
    if(n == 1)
    return false;

    vector<pair<long, long>> interval;

    for(int i=0; i<n; i++)
    interval.push_back({start[i], end[i]});

    sort(interval.begin(), interval.end(), compare);

    for(int i=1; i<n; i++)
    {
        if(interval[i].first < interval[i-1].second)
        return true;
    }

    return false;
}
