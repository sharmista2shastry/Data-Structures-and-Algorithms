//Time Complexity: O(nlogn)

vector<int> waveFormArray(vector<int> &arr, int n) {
    // Write your code here.
    sort(arr.begin(), arr.end());

    for(int i=0; i<n-1; i = i + 2)
    swap(arr[i], arr[i+1]);

    return arr;
}

// Optimised approach with O(n) time complexity

vector<int> waveFormArray(vector<int> &arr, int n) {
    // Write your code here.
    
    for(int i=0; i<n; i = i+2)
    {
        if(i > 0 && arr[i] < arr[i-1])
        swap(arr[i], arr[i-1]);

        if(i < n-1 && arr[i] < arr[i+1])
        swap(arr[i], arr[i+1]);
    }

    return arr;
}
