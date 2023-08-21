#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
    return a.first < b.first;

    return a.second < b.second;
}

void greedy(int n, vector<pair<int, int>> activities)
{
    sort(activities.begin(), activities.end(), cmp);

    // for(int i=0; i<n; i++)
    // cout << activities[i].first << " " << activities[i].second << endl;

    int count = 1;
    int lastIndex = activities[0].second;

    for(int i=1; i<n; i++)
    {
        if(lastIndex <= activities[i].first)
        {
            count++;
            lastIndex = activities[i].second;
        }
    }

    cout << count << endl;
}

int main(){
    
    // write your code here
    int n;
    cin >> n;
    vector<pair<int, int>> activities(n);

    for(int i=0; i<n; i++)
    {
        pair<int, int> p;
        cin >> p.first;
        cin >> p.second;
        activities[i] = p;
    }

    greedy(n, activities);
    return 0;
}#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
    return a.first < b.first;

    return a.second < b.second;
}

void greedy(int n, vector<pair<int, int>> activities)
{
    sort(activities.begin(), activities.end(), cmp);

    // for(int i=0; i<n; i++)
    // cout << activities[i].first << " " << activities[i].second << endl;

    int count = 1;
    int lastIndex = activities[0].second;

    for(int i=1; i<n; i++)
    {
        if(lastIndex <= activities[i].first)
        {
            count++;
            lastIndex = activities[i].second;
        }
    }

    cout << count << endl;
}

int main(){
    
    // write your code here
    int n;
    cin >> n;
    vector<pair<int, int>> activities(n);

    for(int i=0; i<n; i++)
    {
        pair<int, int> p;
        cin >> p.first;
        cin >> p.second;
        activities[i] = p;
    }

    greedy(n, activities);
    return 0;
}
