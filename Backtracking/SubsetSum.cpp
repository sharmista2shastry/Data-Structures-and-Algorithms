//Time Complexity:It has a time complexity of O(2^n), where n is the size of the input array array
//Space Complexity: The space complexity of the code is O(n), where n is the size of the input array arr. This is because the code uses recursion, and the space required for the recursive call stack grows with the depth of the recursion, which is equal to the size of the input array. 

#include<bits/stdc++.h>
using namespace std;

void subsetSum(int *arr, int n, int &count, int sum, int i)
{
    if(i == n)
    {
        if(sum == 0)
        {
            count++;
            return;
        }

        return;
    }

    // Include current element in the sum and recurse
    if (sum - arr[i] >= 0)
    {
        subsetSum(arr, n, count, sum - arr[i], i + 1);
    }

    // Exclude current element from the sum and recurse
    subsetSum(arr, n, count, sum, i + 1);
}

int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        int sum;
        cin >> sum;

        for(int i=0; i<n; i++)
        cin >> arr[i];

        int count = 0;
        
        subsetSum(arr, n, count, sum, 0);
        cout << count << endl;

        delete [] arr;
    }

    return 0;
}
