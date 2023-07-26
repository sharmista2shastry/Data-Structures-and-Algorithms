#include<iostream>
using namespace std;

void helper(int input[], int n, int temp[], int k, int si, int tempsize) 
{
  if (n == 0) 
  {
    if (k == 0) 
    {

      for (int i = 0; i < tempsize; i++) {
        cout << temp[i] << " ";
      }
      cout << endl;
    }

    return;
  }

  helper(input, n - 1, temp, k, si + 1, tempsize);

  temp[tempsize] = input[si];

  helper(input, n - 1, temp, k - input[si], si + 1, tempsize + 1);
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here

    int temp[50];
    helper(input,size,temp,k,0,0);

    return;
}
