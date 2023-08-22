#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool cmpJ(pair<int,int> a, pair<int,int> b)
{
    if(a.second == b.second)
    return a.first < b.first;

    return a.second > b.second;
}

long long lopov(vector<pair<int,int> > jewellery, multiset<int> &ms, int n, int k)
{
    long long totalVal = 0;

    for(int i=0; i<n; i++)
    {
        if(ms.empty())
        break;

        auto itr = ms.lower_bound(jewellery[i].first);

        if(itr == ms.end())
        continue;

        else
        {
            totalVal += jewellery[i].second;
            ms.erase(itr);
        }
    }

    return totalVal;
}

int main()
{
    int n,k;
    cin >> n >> k;

    vector<pair<int,int> > jewellery(n);
    vector<int> bags(k);

    for(int i=0; i<n; i++)
    cin >> jewellery[i].first >> jewellery[i].second;

    for(int i=0; i<k; i++)
    cin >> bags[i];

    multiset<int> ms;

    for(int i=0; i<k; i++)
    ms.insert(bags[i]);

    sort(jewellery.begin(), jewellery.end(), cmpJ);

    cout << lopov(jewellery, ms, n, k) << endl;

    return 0;
}
