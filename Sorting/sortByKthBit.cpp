#include <bits/stdc++.h>

vector<int> sortArrayByKBit(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<int> k0;
    vector<int> k1;

    for(int i=0; i<n; i++)
    {
        int kth_bit = (arr[i] >> k-1) & 1;

        if( kth_bit == 0) 
        {
            k0.push_back(arr[i]);
        }
        
        else 
        k1.push_back(arr[i]);
    }

    int j = 0;

    for(int i=0; i<k0.size(); i++)
    arr[j++] = k0[i];

    for(int i=0; i<k1.size(); i++)
    arr[j++] = k1[i];

    return arr;
}

// More optimised approach which uses only one array

#include <bits/stdc++.h>

vector<int> sortArrayByKBit(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<int> k1;
    int p = 0;

    for(int i=0; i<n; i++)
    {
        int kth_bit = (arr[i] >> k-1) & 1;

        if( kth_bit == 0) 
        arr[p++] = arr[i];
        
        else 
        k1.push_back(arr[i]);
    }

    int j = 0;

    for(int i=p; i<n; i++)
    arr[i] = k1[j++];

    return arr;
}
