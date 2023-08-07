# include <iostream>
# include <vector>
using namespace std;

void solve(vector<int> a, int start, int end, int targetSum)
{
    while(start < end)
    {
        if(a[start] + a[end] == targetSum)
        {
            cout << start << " " << end << endl;
            return;
        }

        else if(a[start] + a[end] < targetSum)
        start++;

        else
        end--;
    }

    cout << "Not Found!" << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, targetSum;
        cin >> n >> targetSum;

        vector<int> a(n);

        for(int i=0; i<n; i++)
        cin >> a[i];

        solve(a, 0, n-1, targetSum);
    } 

    return 0;
}