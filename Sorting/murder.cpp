#include<bits/stdc++.h>
using namespace std;

long long merge(int left, int mid, int right, vector<long long> &arr, vector<long long> &temp)
{
    int k = 0, i = left, j = mid;
    long long finalSum = 0;

    while(i < mid && j <= right)
    {
        if(arr[i] < arr[j])
        {
            finalSum += (right-j+1) * arr[i];
            temp[k++] =arr[i++];
        }

        else
        temp[k++] = arr[j++];
    }

    while(i < mid)
        temp[k++] = arr[i++];

    while(j <= right)
    temp[k++] = arr[j++];

    for(i=left, k=0; i<=right; i++, k++)
    arr[i] = temp[k];

    return finalSum;
}

long long mergeSort(int left, int right, vector<long long> &arr, vector<long long> &temp)
{
    long long finalSum = 0;

    if(right > left)
    {
        int mid = (left + right) / 2;
        finalSum = mergeSort(left, mid, arr, temp);
        finalSum += mergeSort(mid+1, right, arr, temp);
        finalSum += merge(left, mid+1, right, arr, temp);
    }

    return finalSum;
}

long long solve(int n, vector<long long> arr)
{
    vector<long long> temp(n);
    return mergeSort(0, n-1, arr, temp);
}

int main(){
    // write your code
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<long long> arr(n);

        for(int i=0; i<n; i++)
        cin >> arr[i];

        cout << solve(n, arr) << endl;
    }
    return 0;
}
