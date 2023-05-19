#include<bits/stdc++.h>
using namespace std;

bool isSafe(int res[10][10], int row, int col, int n)
{
    for(int i=0; i<row; i++)
    {
        if(res[i][col] == 1)
        return false;
    }

    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
    {
        if(res[i][j] == 1)
        return false;
    }

    for(int i=row, j=col; i>=0 && j<n; i--, j++)
    {
        if(res[i][j] == 1)
        return false;
    }

    return true;
}

void NQueen(int res[10][10], int row, int n)
{
    if(row == n)
    {
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < n; c++)
            {
                cout << res[r][c] << " ";
            }
        }
        cout << endl;
        return;
    }

    for(int col=0; col<n; col++)
    {
        if(isSafe(res, row, col, n))
        {
            res[row][col] = 1;
            NQueen(res, row+1, n);
            res[row][col] = 0;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int res[10][10];

    // We can use memset also to initialise this board with 0
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        res[i][j] = 0;
    }

    NQueen(res, 0, n);
    // write your code here
    return 0;
}
