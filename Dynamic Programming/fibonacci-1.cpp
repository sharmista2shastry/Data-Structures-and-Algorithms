int fibo_helper(int n, int *arr)
{
  if(n <= 1)
    return n;
  
  //Check if ans already exists
  if(arr[n] != -1)
    return arr[n];
  
  //Calculate and save
  int a = fibo_helper(n-1, arr);
  int b = fibo_helper(n-2, arr);
  
  arr[n] = a+ b;
  return arr[n];
}

int main()
{
  int n;
  cin >> n;
  int *arr = new int[n+1];
  for(int i=0; i<=n; i++)
    arr[i] = -1;
  
  return fibo_helper(n,arr);
}
