#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> A, vector<int> B)
{
    int i = 0, j = 0, k = 0, n = A.size(), m = B.size();
    vector<int> C(n+m);

    while(i < n && j < m)
    {
        if(A[i] < B[j])
        C[k++] = A[i++];

        else
        C[k++] = B[j++];
    }

    while(i < n)
    {
        C[k++] = A[i++];
    }

    while(j < m)
    {
        C[k++] = B[j++];
    }

    return C;
}

vector<int> mergeSort(vector<int> arr, int l, int r)
{
    if (l == r)
    {
        vector<int> result;
        result.push_back(arr[l]);  // Push the single element onto the vector
        return result;
    }

    int mid = (l + r) / 2;

    vector<int> A = mergeSort(arr, l, mid);
    vector<int> B = mergeSort(arr, mid + 1, r);

    return merge(A, B);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++)
    cin >> arr[i];

    vector<int> res = mergeSort(arr,0,n-1);

    for(int i=0; i<n; i++)
    cout << res[i] << " ";

    return 0;
}
