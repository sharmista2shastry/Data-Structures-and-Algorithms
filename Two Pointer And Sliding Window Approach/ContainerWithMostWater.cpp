#include <bits/stdc++.h>

int maxArea(vector<int>& height) {
    // Write your code here.
    int lh = 0, rh = height.size()-1, maxArea = INT_MIN;

    while(lh < rh)
    {
        int area = min(height[lh], height[rh]) * (rh-lh);
        maxArea = max(maxArea, area);

        if(height[lh] < height[rh])
        lh++;

        else
        rh--;
    }

    return maxArea;
}
