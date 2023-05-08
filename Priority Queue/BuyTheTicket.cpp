#include <queue>
int buyTicket(int *arr, int n, int k) {
    // Write your code here
    priority_queue<int> pq;
    queue<int> q;

    for(int i=0; i<n; i++)
    {
        pq.push(arr[i]);
        q.push(i);
    }

    int T = 0;

    while(1)
    {
        int frontIndex = q.front();

        if(pq.top() == arr[frontIndex] && frontIndex == k)
        {
            T++;
            pq.pop();
            q.pop();
            break;
        }

        else if(pq.top() == arr[frontIndex])
        {
            T++;
            pq.pop();
            q.pop();
            continue;
        }

        q.pop();
        q.push(frontIndex);
    }

    return T;
}
