#include <vector>
#include <queue>

vector<int> kLargest(int arr[], int n, int k){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
     priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<k; i++)
    pq.push(arr[i]);                        //klogk

    for(int i=k; i<n; i++)
    {
        if(arr[i] > pq.top())
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
