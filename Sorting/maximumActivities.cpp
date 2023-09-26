#include<bits/stdc++.h>

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n = start.size();
    vector<pair<int, int>>activity(n);

    for(int i=0; i<n; i++)
    {
        activity[i].first = start[i];
        activity[i].second = finish[i];
    }

    sort(activity.begin(), activity.end(), cmp);

    int count = 1;
    int prevIndex = 0;

    for(int i=1; i<n; i++)
    {
        if (activity[i].first >= activity[prevIndex].second) {
          count++;
          prevIndex=i;
        }
    }

    return count;
}
