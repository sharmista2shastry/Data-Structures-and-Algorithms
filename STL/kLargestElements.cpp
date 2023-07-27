#include<queue>
#include<vector>

vector<int> kLargest(int arr[], int n, int k) {
    // Write your code here
    priority_queue<int> pq;
    vector<int> ans;

    for(int i=0; i<n; i++)
    pq.push(arr[i]);

    for(int i=0; i<k; i++)
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}
