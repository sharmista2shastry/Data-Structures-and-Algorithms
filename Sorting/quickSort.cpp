#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[end];
    int i = start - 1; // Initialize the index of smaller element

    for (int j = start; j <= end - 1; j++) {
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quickSort(vector<int> &arr, int start, int end) 
{
    if(start >= end) 
    return;

    int index = partition(arr, start, end); 
    quickSort(arr, start, index-1);  
    quickSort(arr, index+1, end);
}

int main()
{
    int n;
    cin >> n; // 5
    vector<int> arr(n); // [2 4 3 9 1]

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++)
    cout << arr[i] << " ";
}
