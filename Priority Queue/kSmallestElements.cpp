#include <queue>
#include <vector>

vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
    priority_queue<int> pq;

    for(int i=0; i<k; i++)
    pq.push(arr[i]);                        //klogk

    for(int i=k; i<n; i++)
    {
        if(arr[i] < pq.top())
        {
            pq.pop();                       //(n-k)logk
            pq.push(arr[i]);
        }
    }

    vector<int> v;

    for(int i=0; i<k; i++)              //k
    {
        v.push_back(pq.top());
        pq.pop();
    }

    return v;
}
