#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

int helper(char input[], int n, int i)
{
    if(n == 0)
    return 0;

    char c = input[0] - '0';

    return pow(10, i) *c + helper(input + 1, n-1, i-1); 
}

int stringToNumber(char input[]) {
    // Write your code here
    int n = strlen(input);
    return helper(input, n, n-1);
}
