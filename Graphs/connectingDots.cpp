//Time Complexity: O(n^2 * m^2)

bool helper(vector<vector<char>> &board, bool **visited, int n, int m, int i, int j, int &count, int row, int col)
{
    if(i-1 == row && j == col)
    return true;

    visited[i][j] = true;
    count++;

    bool ans = false;

    if(j+1 < m && board[i][j+1] == board[i][j] && !visited[i][j+1])
    {
        ans = helper(board, visited, n, m, i, j + 1, count, row, col);
        visited[i][j+1] = false;
    }

    if(i+1 < n && board[i+1][j] == board[i][j] && !visited[i+1][j])
    {
        ans = helper(board, visited, n, m, i + 1, j, count, row, col);
        visited[i + 1][j] = false;
    }

    if(j-1 >= 0 && board[i][j-1] == board[i][j] && !visited[i][j-1])
    {
        ans = helper(board, visited, n, m, i, j - 1, count, row, col);
        visited[i][j-1] = false;
    }

    if(i-1 >= 0 && board[i-1][j] == board[i][j] && !visited[i-1][j])
    {
        ans = helper(board, visited, n, m, i-1, j, count, row, col);
        visited[i-1][j] = false;
    }

    return ans;
}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    bool **visited = new bool*[n];

    for(int i=0; i<n; i++)
    {
        visited[i] = new bool[m];
        for(int j=0; j<m; j++)
        {
            visited[i][j] = false;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int count = 0;
            if(visited[i][j] == false)
            {
                if(helper(board, visited, n, m, i, j, count, i, j))
                {
                    if(count >= 4)
                    return true;
                }
            }
        }
    }

    return false;
}
