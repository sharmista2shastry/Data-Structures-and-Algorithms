#include <unordered_map>

void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int, int> a1;

    for(int i=0; i<n; i++)
    {
        a1[arr1[i]]++;
    }

    for(int i=0; i<m; i++)
    {
        if(a1[arr2[i]] > 0)
        {
            a1[arr2[i]]--;
            cout << arr2[i] << endl;
        }
    }

}
