#include <bits/stdc++.h>

typedef pair<int, pair<int, int>> pi;

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<int> res;

    for(int i=0; i<input.size(); i++)
    pq.push({input[i]->at(0), {i, 0}});

    while(!pq.empty())
    {
        pi curr = pq.top();
        pq.pop();

        int currVal = curr.first;
        int arrIdx = curr.second.first;
        int elementIdx = curr.second.second;

        res.push_back(currVal);

        if(elementIdx + 1 < input[arrIdx]->size())
        pq.push({input[arrIdx]->at(elementIdx + 1), {arrIdx, elementIdx + 1}});
        
    }

    return res;
}
