#include <unordered_map>
#include <vector>
#include <climits>

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_map<int, int> index;

    int maxlen = 0, startIndex = 0, minSI = INT_MAX;

    for(int i=0; i<n; i++) {
        index[arr[i]] = i;
    }

    for(int i=0; i<n; i++) {
        if(index[arr[i]] == -1)
            continue;

        index[arr[i]] = -1;

        int len = 1, j = 1;
        startIndex = i;

        while(index.count(arr[i]+j) > 0) {
            index[arr[i]+j] = -1;
            len++;
            j++;
        }

        j=1;

        while(index.count(arr[i]-j) > 0) {
            startIndex = index[arr[i]-j];
            index[arr[i]-j] = -1;
            len++;
            j++;
        }

        if(len >= maxlen) {
            if(startIndex < minSI || len > maxlen)
            {
                minSI = startIndex;
            }
            maxlen = len;
        }
    }

    vector<int> ans;
    ans.push_back(arr[minSI]);
    ans.push_back(arr[minSI]+maxlen-1);

    return ans;
}
