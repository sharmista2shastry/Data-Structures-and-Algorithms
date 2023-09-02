#include <bits/stdc++.h> 

long long merge(long long *arr, int left, int mid, int right)
{
    int i = left, j = mid, k = 0; 
    long long inversion = 0;
    long long *temp = new long long[right-left+1]; 
    
    while(i < mid && j <= right)
    {
        if(arr[i] < arr[j])
        temp[k++] = arr[i++];

        else
        {
            temp[k++] = arr[j++];
            inversion += (mid - i); 
        }
    }

    while(i < mid)
    temp[k++] = arr[i++];

    while(j <= right)
    temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++)  
    arr[i] = temp[k];  
 
    return inversion; 
}

long long mergeSort(long long *arr, int left, int right)
{
    long long inversion = 0;

    if(right > left) 
    {
        int mid = (left + right) / 2;

        inversion = mergeSort(arr, left, mid); 
        inversion += mergeSort(arr, mid+1, right); 
        inversion += merge(arr, left, mid+1, right);
    }

    return inversion;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(arr, 0, n-1);
}
