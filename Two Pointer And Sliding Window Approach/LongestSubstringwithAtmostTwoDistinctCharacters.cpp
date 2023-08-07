#include <bits/stdc++.h>

int lengthOfLongestSubstring(string s) {
    // Write your code here.
    unordered_map<char, int> mp;
    int start = 0;
    int end = 0;
    int len = 1;
    int maximum = INT_MIN;

    while(end < s.length())
    {
        if(mp.count(s[end])> 0 && mp.size() <= 2)
        {
            mp[s[end]]++;
            end++;
        }

        else
        {
            if(mp.size() < 2)
            {
                mp[s[end]]++;
                end++;
            }

            else
            {
                len = end-start;
                maximum = max(maximum, len);
                mp[s[end]]++;

                while(mp.size() > 2)
                {
                    if(mp[s[start]] == 1)
                    mp.erase(s[start]);

                    else
                    mp[s[start]]--;

                    start++;
                }

                end++;
            }
        }
    }

    len = end-start;
    maximum = max(maximum, len);

    return maximum;
}
