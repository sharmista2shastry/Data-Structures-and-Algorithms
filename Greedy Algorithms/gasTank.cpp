#include <bits/stdc++.h>

int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) 
{
    // Write your code here.
    int total_gas = 0;
    int total_cost = 0;

    for(int i=0; i<n; i++)
    {
        total_gas += gas[i];
        total_cost += cost[i];
    }

    if(total_gas < total_cost)
    return -1;

    int ans;
    int fuelUsed = 0;

    for(int i=0; i<n; i++)
    {
        fuelUsed += gas[i];
        fuelUsed -= cost[i];

        if(fuelUsed < 0)
        {
            fuelUsed = 0;
            ans = INT_MAX;
            continue;
        }

        ans = min(ans, i);
    }

    return ans;
}
