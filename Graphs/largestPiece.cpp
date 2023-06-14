//Time Complexity: O(n^2)

void helper(vector<vector<int>> &cake, bool **visited, int n, int i, int j, int &count)
{
    visited[i][j] = true;
    count ++;

    if(i-1 >=0 && cake[i-1][j] == 1 && !visited[i-1][j])
    {
        helper(cake, visited, n, i-1, j, count);
        //visited[i-1][j] = false;
    }

    if(j+1 < n && cake[i][j+1] == 1 && !visited[i][j+1])
    {
        helper(cake, visited, n, i, j+1, count);
        //visited[i][j+1] = false;
    }

    if(i+1 < n && cake[i+1][j] == 1 && !visited[i+1][j])
    {
        helper(cake, visited, n, i+1, j, count);
        //visited[i+1][j] = false;
    }

    if(j-1 >=0 && cake[i][j-1] == 1 && !visited[i][j-1])
    {
        helper(cake, visited, n, i, j-1, count);
        //visited[i][j-1] = false;
    }
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    int maxPiece = 0;

    bool **visited = new bool*[n];

    for(int i=0; i<n; i++)
    {
        visited[i] = new bool[n];
        for(int j=0; j<n; j++)
        {
            visited[i][j] = false;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int count = 0;
            if(cake[i][j] == 1 && !visited[i][j])
            {
                helper(cake, visited, n, i, j, count);
                maxPiece = max(maxPiece, count);
            }
        }
    }

    return maxPiece;
}
