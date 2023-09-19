#include<bits/stdc++.h>
using namespace std;

void sortSkills(vector<int> arr, int n)
{
    for(int i=1; i < n-1; i++)
    {   
        if(arr[i] > arr[i+1] && abs(arr[i] - arr[i+1]) <= 1)
        swap(arr[i], arr[i+1]);

        while(i >= 1 && arr[i] < arr[i-1] && abs(arr[i] - arr[i-1]) <= 1)
        {
            swap(arr[i], arr[i-1]);
            i--;
        }

        // if(arr[i] > arr[i+1] && abs(arr[i] - arr[i+1]) <= 1)
        // i--;
    }

    for(int i=0; i<n-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
    return;
}

int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> emp(n);

        for(int i=0; i<n; i++)
        cin >> emp[i];

        sortSkills(emp, n);
    }
    return 0;
}
