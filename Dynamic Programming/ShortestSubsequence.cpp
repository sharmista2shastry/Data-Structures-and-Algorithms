//Using Brute Force

#include <climits>
#include <unordered_map>

void substrS(string s, string str, unordered_map<string, int> &mpS)
{
    if(s.length() == 0)
    {
        mpS[str]++;
        return;
    }

    substrS(s.substr(1), str + s[0], mpS);
    substrS(s.substr(1), str, mpS);
}

void substrV(string v, string str, unordered_map<string, int> &mpV)
{
    if(v.length() == 0)
    {
        mpV[str]++;
        return;
    }

    substrV(v.substr(1), str + v[0], mpV);
    substrV(v.substr(1), str, mpV);
}

int solve(string s, string v) {
    // Write your code here
    unordered_map<string, int> mpS, mpV;
    substrS(s, "", mpS);
    substrV(v, "", mpV);

    int minLen = INT_MAX;

    for(const auto& pair: mpS)
    {
        if(mpV.find(pair.first) == mpV.end())
        {
            int len = pair.first.length();
            minLen = min(minLen, len);
        }
    }

    return minLen;
}
