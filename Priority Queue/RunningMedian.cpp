#include <queue>
#include <vector>

void findMedian(int *arr, int n)
{
    // Write your code here
    if(n == 0)
    return;

    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;

    maxpq.push(arr[0]);
    cout << arr[0] << " ";

    for(int i=1; i<n; i++)
    {
        if(arr[i] <= maxpq.top())
        {
            maxpq.push(arr[i]);

            if(maxpq.size() - minpq.size() > 1)
            {
                int top = maxpq.top();
                maxpq.pop();
                minpq.push(top);
            }
        }

        else
        {
            minpq.push(arr[i]);

            if(minpq.size() - maxpq.size() > 1)
            {
                int top = minpq.top();
                minpq.pop();
                maxpq.push(top);
            }
        }

        if((maxpq.size() + minpq.size())%2 == 0)
            {
                int ans = (maxpq.top() + minpq.top())/2;
                cout << ans << " ";
            }

            else
            {
                if(maxpq.size() > minpq.size())
                cout << maxpq.top() << " ";

                else
                cout << minpq.top() << " ";
            }
    }
}
