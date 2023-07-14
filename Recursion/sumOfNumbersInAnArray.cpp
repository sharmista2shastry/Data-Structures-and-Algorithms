int helper(int input[], int n, int &s)
{
  if(n == 0)
  return s;

  s += input[0];

  return helper(input+1, n-1, s);
}

int sum(int input[], int n) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
    int s = 0;
    return helper(input, n, s);
}
