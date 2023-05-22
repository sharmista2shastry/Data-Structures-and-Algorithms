//Time Complexity:It has a time complexity of O(2^n), where n is the size of the input array array
//Space Complexity: The space complexity of the code is O(n), where n is the size of the input array arr. This is because the code uses recursion, and the space required for the recursive call stack grows with the depth of the recursion, which is equal to the size of the input array. 

#include <bits/stdc++.h> 
using namespace std; 
int subsetCount(int arr[], int n, int index, int target) 
{ 
    if (index == n) 
    {
        if (target == 0) 
        return 1; 
        
        else return 0; 
    } 

    int count = 0; 

    if (target - arr[index] >= 0) 
    { 
        count += subsetCount(arr, n, index + 1, target - arr[index]); 
    } 

    count += subsetCount(arr, n, index + 1, target); 
    
    return count;
} 

int main() 
{ 
    int t; cin >> t; 
    while (t--) 
    { 
        int n, k; 
        cin >> n >> k; 
        int arr[n]; 

        for (int i = 0; i < n; i++)
        { 
            cin >> arr[i]; 
        } 

        cout << subsetCount(arr, n, 0, k) << endl;
    }
}
