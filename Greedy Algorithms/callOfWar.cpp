#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    
    // write your code here
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<pair<ll, ll>> enemy(n);
        for(int i=0; i<n; i++)
        cin >> enemy[i].first >> enemy[i].second;

        vector<ll> postDetonation(n);

        for(int i=1; i<n; i++)
        {
            if(enemy[i-1].second < enemy[i].first)
            postDetonation[i] = enemy[i].first - enemy[i-1].second;

            else
            postDetonation[i] = 0;
        }

        if(enemy[n-1].second < enemy[0].first)
            postDetonation[0] = enemy[0].first - enemy[n-1].second;

            else
            postDetonation[0] = 0;

            ll total = 0;
            ll minBullets = LONG_LONG_MAX;

            for(int i=0; i<n; i++)
            total += postDetonation[i];

            for(int i=0; i<n; i++)
            minBullets = min(minBullets, enemy[i].first + (total - postDetonation[i]));

            cout << minBullets << endl;
    }

    return 0;
}
