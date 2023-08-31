#include<bits/stdc++.h>

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    int currArr = 0, currDep = 0, p = 0, maxP = 0;
    sort(at, at+n);
    sort(dt, dt+n);

    while(currArr < n && currDep < n)
    {
        if(at[currArr] <= dt[currDep])
        {
            p++;
            maxP = max(maxP, p);
            currArr++;
        }

        else if(at[currArr] > dt[currDep])
        {
            p--;
            currDep++;
        }
    }

    return maxP;
}
