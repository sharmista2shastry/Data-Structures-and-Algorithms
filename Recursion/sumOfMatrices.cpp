#include<iostream>
using namespace std;

void sum(int arr1[10][10], int arr2[10][10], int m, int n, int i, int j)
{
    if(i >= m)
    return;

    if(j >= n)
    {
        sum(arr1, arr2, m, n, i+1, 0);
        return;
    }

    cout << arr1[i][j] + arr2[i][j] << " ";

    sum(arr1, arr2, m, n, i, j+1);
}

int main()
{
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    cout << "Enter the elements of the first array: ";

    int arr1[10][10], arr2[10][10];

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr1[i][j];
        }
    }

    cout << "Enter the elements of the sec array: ";

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr2[i][j];
        }
    }

    sum(arr1, arr2, m, n, 0, 0);

    return 0;
}
