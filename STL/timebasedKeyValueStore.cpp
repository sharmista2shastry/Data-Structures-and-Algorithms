/*
    Your Timebased object will be instantiated and called as such:

    Timebased* obj = new Timebased();
    obj->setKey(key,value,timestamp);
    string ans = obj->getValue(targetKey,targetTimestamp);
*/
#include <bits/stdc++.h>
using namespace std;

class Timebased 
{
    public:
    map<string, map<int, string, greater<int>>> mp;

        Timebased() {
            // Intialise your data structure here.
            mp[""][-1] = "";
        }

    void setKey(string key, string val, int timestamp) {
        // Write your code here.
        mp[key][timestamp] = val;
    }

    string getValue(string targetKey, int targetTimestamp) {
        // Write your code here.
        auto it = mp.find(targetKey);
        if (it == mp.end())
        return "-1";

        const map<int, string, greater<int>>& timestampMap = it->second;
        auto it2 = timestampMap.lower_bound(targetTimestamp);
        if (it2 == timestampMap.end())
        return "-1";

        return it2->second;
    }
};
