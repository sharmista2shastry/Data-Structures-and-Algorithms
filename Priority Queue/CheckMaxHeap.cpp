bool isMaxHeap(int arr[], int n) {
    // Write your code here
    for(int i=1; i<n; i++)
    {
        int childIndex = i;
        int parentIndex = (childIndex-1)/2;

        if(arr[parentIndex] < arr[childIndex])
        return false;
    }

    return true;
}
