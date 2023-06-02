//Using Brute Force

int lcs(string S, string T)
{
  if(S.length() == 0 || T.length() == 0)
    return 0;
  
  if(S[0] == T[0])
    return 1 + lcs(S.substr(1), T.substr(1));
  
  int a = lcs(S.substr(1), T);
  int b = lcs(S, T.substr(1));
  int c = lcs(S.substr(1), T.substr(1));
  
  return max(a, max(b,c));
}

// Using memoization
//Time and Space Complexity: O(mn) as (m+1)*(n+1) calls are made

int lcs(string S, string T, int **output)
{
  int m = S.length();
  int n = T.length();
  
  if(m == 0 || n == 0)
    return 0;
  
  if(output[m][n] != -1)
    return output[m][n];
  
  int ans, a, b, c;
  
  if(S[0] == T[0])
    ans = 1 + lcs(S.substr(1), T.substr(1), output);
  
  else
  {
    a = lcs(S.substr(1), T, output);
    b = lcs(S, T.substr(1), output);
    c = lcs(S.substr(1), T.substr(1));
    
    ans = max(a, max(b, c));
  }
  
  output[m][n] = ans;
  return ans;
}

int** allocate2DArray(int m, int n) {
  int **output = new int*[m+1];
  
  for(int i=0; i<=m; i++)
    output[i] = new int[n+1];
  
  for(int i=0; i<=m; i++)
  {
    for(int j=0; j<=n; j++)
    {
      output[i][j] = -1;
    }
  }
  
  return output;
}

//Using DP

int lcs(string S, string T, int **output)
{
  int m = S.length();
  int n = T.length();
  
  for(int i=0; i<=m; i++)
    output[i][0] = 0;
  
  for(int j=0; j<=n; j++)
    output[0][j] = 0;
  
  for(int i=1; i<=m; i++)
  {
    for(int j=1; j<=n; j++)
    {
      if(S[m-i] == T[n-j])
        output[i][j] = 1 + output[i-1][j-1];
      
      else
      {
        int a = output[i-1][j];
        int b = output[i][j-1];
        int c = output[i-1][j-1];
        
        output[i][j] = max(a, max(b,c));
      }
    }
  }
  
  return output[m][n];
}

int** allocate2DArray(int m, int n) {
  int **output = new int*[m+1];
  
  for(int i=0; i<=m; i++)
    output[i] = new int[n+1];
  
  return output;
}
