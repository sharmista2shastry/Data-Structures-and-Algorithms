#include <bits/stdc++.h> 

int minProduct(vector<int> &arr, int n, int k) {
    // Write your code here.

    priority_queue<int, vector<int>, greater<int>> pq;
    int mod = 1000000000 + 7;


    for(int i=0; i<n; i++)
    pq.push(arr[i]);

    int prod = 1;

    while(k-- && !pq.empty())
    {
        prod = (prod *(long long)pq.top())%mod;
        pq.pop();
    }

    return prod;
}

//Alternative Solution

#include <bits/stdc++.h> 

int minProduct(vector<int> &arr, int n, int k) {
    // Write your code here.

    priority_queue<int, vector<int>> pq;
    int mod = 1000000000 + 7;


    for(int i=0; i<k; i++)
    pq.push(arr[i]);

    for(int i=k; i<n; i++)
    {
        if(arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int prod = 1;

    while(!pq.empty())
    {
        prod = (prod *(long long)pq.top())%mod;
        pq.pop();
    }

    return prod;
}
