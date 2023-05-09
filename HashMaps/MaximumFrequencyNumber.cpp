#include <unordered_map>

int highestFrequency(int arr[], int n) {
    // Write your code here
    int maximum = 0;
    unordered_map<int, int> freq;

    for(int i=0; i<n; i++)
    {
        freq[arr[i]]++;
        if(freq[arr[i]] > maximum)
        maximum = freq[arr[i]];
    }

    for(int i=0; i<n; i++)
    {
        if(freq[arr[i]] == maximum)
        return arr[i];
    }
}
