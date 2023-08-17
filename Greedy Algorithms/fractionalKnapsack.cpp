#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    double val1 = (double)(p1.first) / (double)p1.second;
    double val2 = (double)(p2.first) / (double)p2.second;

    return val1 > val2;
}

void fractionalKnapsack(int n, int capacity, vector<pair<int, int>> items)
{
    sort(items.begin(), items.end(), compare);

    // for(int i=0; i<n; i++)
    // cout << items[i].first << " " << items[i].second << endl;

    double v = 0;

    for(int i=0; i<n; i++)
    {
        if(capacity - items[i].second >= 0)
        {
            capacity -= items[i].second;
            v += (double)items[i].first;
        }

        else if(capacity - items[i].second < 0)
        {
            v += capacity * ((double)items[i].first / (double)items[i].second);
            break;
        }
    }

    cout << fixed << setprecision(6) << v << endl;
}

int main(){
    
    // write your code here
    int n, capacity;
    cin >> n >> capacity;

    vector<pair<int,int>> items(n);

    for(int i=0; i<n; i++)
    {
        int val, weight;
        cin >> val >> weight;
        pair<int, int> p;
        p.first = val;
        p.second = weight;
        items[i] = p;
    }

    fractionalKnapsack(n, capacity, items);

    return 0;
}
