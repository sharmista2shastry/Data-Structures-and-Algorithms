#include <bits/stdc++.h>

class triplet{
    public:
    int time, loss, index;
};

bool cmp(triplet a, triplet b)
{
    if ((static_cast<double>(a.time) / a.loss) == (static_cast<double>(b.time) / b.loss))
    {
        return a.index < b.index;
    }

    return ((static_cast<double>(a.time) / a.loss) < (static_cast<double>(b.time) / b.loss));
}


vector<int> minLoss(int n, vector<int> &time, vector<int> &loss) {
    // Write your code here.
    vector<triplet> arr(n);
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        triplet t;
        t.time = time[i];
        t.loss = loss[i];
        t.index = i+1;

        arr[i] = t;
    }

    sort(arr.begin(), arr.end(), cmp);

    for(int i=0; i<n; i++)
    result[i] = arr[i].index;

    return result;
}
