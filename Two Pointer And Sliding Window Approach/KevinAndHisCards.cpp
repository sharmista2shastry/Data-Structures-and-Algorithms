#include <bits/stdc++.h> 
vector<int> diffSimCards(vector<int> &pack1, int n, vector<int> &pack2, int m)
{
    //  Write your code here.
    vector<int> ans;

    int inter = 0, i = 0, j = 0;
    unordered_set<int> s;

    while(i < n && j < m)
    {
        if(pack1[i] == pack2[j])
        {
            inter++;
            s.insert(pack1[i]);
            i++;
            j++;
        }

        else if(pack1[i] < pack2[j])
        {
            s.insert(pack1[i]);
            i++;
        }

        else if(pack1[i] > pack2[j])
        {
            s.insert(pack2[j]);
            j++;
        }
    }

    while(i < n)
    s.insert(pack1[i++]);

    while(j < m)
    s.insert(pack2[j++]);

    ans.push_back(s.size());
    ans.push_back(inter);

    return ans;
}
