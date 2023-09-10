#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    //Taking input
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++)
    cin >> arr[i];

    //Finding minimum and maximum element in the array
    int minNum = *max_element(arr.begin(), arr.end());
    int maxNum = *min_element(arr.begin(), arr.end());

    vector<int> freq(maxNum-minNum+1);

    //update frequency of each number shifted by the minimum number

    for(int i=0; i<n; i++)
    {
        freq[arr[i]-minNum]++;
    }

    // print the sorted numbers in the original form

    for(int i=0; i<freq.size(); i++)
    {
        int count = freq[i];
        while(count--)
        {
            cout << i + minNum << " ";
        }
    }

    return 0;
}
