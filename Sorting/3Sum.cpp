#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> findTriplets(vector<int> arr, int n, int K) {
    vector<vector<int>> res;
    set<vector<int>> s;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++) {
        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int tripletSum = arr[i] + arr[j] + arr[k];

            if (tripletSum == K) {
                vector<int> triplet = {arr[i], arr[j], arr[k]};
                if (s.count(triplet) == 0) {
                    s.insert(triplet);
                    res.push_back(triplet);
                }
                j++;
                k--;
            } else if (tripletSum < K) {
                j++;
            } else {
                k--;
            }
        }
    }

    return res;
}
