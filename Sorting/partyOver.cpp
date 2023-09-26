#include <bits/stdc++.h>

bool cmp(string a, string b)
{
    int minLength = min(a.length(), b.length());

    for(int i=1; i<=minLength; i++)
    {
        char lastA = a[a.length()-i];
        char lastB = b[b.length()-i];

        if(lastA < lastB)
        return true;

        else if(lastA > lastB)
        return false;
    }

    return a.length() < b.length();
}

vector<string> ninjaParty(vector<string> &arr)
{
    //write your code here
    sort(arr.begin(), arr.end(), cmp);

    return arr;
}
