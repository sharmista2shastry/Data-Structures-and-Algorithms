bool findpath(vector<vector<char>> &board, int i, int j, int n, int m, string word, bool **visited)
{
    if(word.length() == 0)
    return true;

    visited[i][j] = true;

    bool ans = false;

    if(i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] == word[0] && !visited[i-1][j-1] && !ans)
    {
        ans = findpath(board, i-1, j-1, n, m, word.substr(1), visited);
        visited[i-1][j-1] = false;
    }

    if(i-1 >=0 && board[i-1][j] == word[0] && !visited[i-1][j] && !ans)
    {
        ans = findpath(board, i-1, j, n, m, word.substr(1), visited);
        visited[i-1][j] = false;
    }

    if(i-1 >=0 && j+1 < m && board[i-1][j+1] == word[0] && !visited[i-1][j+1] && !ans)
    {
        ans = findpath(board, i-1, j+1, n, m, word.substr(1), visited);
        visited[i-1][j+1] = false;
    }

    if(j+1 < m && board[i][j+1] == word[0] && !visited[i][j+1] && !ans)
    {
        ans = findpath(board, i, j+1, n, m, word.substr(1), visited);
        visited[i][j+1] = false;
    }

    if(i+1 < n && j+1 < m && board[i+1][j+1] == word[0] && !visited[i+1][j+1] && !ans)
    {
        ans = findpath(board, i+1, j+1, n, m, word.substr(1), visited);
        visited[i+1][j+1] = false;
    }

    if(i+1 < n && board[i+1][j] == word[0] && !visited[i+1][j] && !ans)
    {
        ans = findpath(board, i+1, j, n, m, word.substr(1), visited);
        visited[i+1][j] = false;
    }

    if(i+1 < n && j-1 >=0 && board[i+1][j-1] == word[0] && !visited[i+1][j-1] && !ans)
    {
        ans = findpath(board, i+1, j-1, n, m, word.substr(1), visited);
        visited[i+1][j-1] = false;
    }

    if(j-1 >=0 && board[i][j-1] == word[0] && !visited[i][j-1] && !ans)
    {
        ans = findpath(board, i, j-1, n, m, word.substr(1), visited);
        visited[i][j-1] = false;
    }

    return ans;
}

bool helper(vector<vector<char>> &board, int i, int j, int n, int m, string word)
{
    bool **visited = new bool*[n];

    for(int k=0; k<n; k++)
    {
        visited[k] = new bool[m]; 
        for(int l=0; l<m; l++)
        {
            visited[k][l] = false;
        }
    }

    for(int row=0; row<n; row++)
    {
        for(int col=0; col<m; col++)
        {
            if(board[row][col] == word[0])
            {
                i = row;
                j = col;
                if(findpath(board, i, j, n, m, word.substr(1), visited))
                return true;
            }
        }
    }

    return false;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    if(m == 0 && n == 0)
    return false;

    string word = "CODINGNINJA";

    if(word.length() > (n*m))
    return false;

    if(helper(board, 0, 0, n, m, word))
    return 1;

    return 0;
}
