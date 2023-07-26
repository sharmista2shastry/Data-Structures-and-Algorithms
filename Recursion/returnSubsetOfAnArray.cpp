/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

DonÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂ¢ÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂÃÂt print the subsets, just save them in output.
***/
#include<iostream>
using namespace std;

int index = 1;

int helper(int input[], int n, int output[][20], int i)
{
	if(n==0)
	{
		output[0][0] = 0;
		return 1;
	}

	int smallOutput = helper(input,n-1,output,i+1);

	int row = 0;

	for(int j=index; j<2*smallOutput; j++)
	{
		output[j][0] = output[row][0] + 1;
		output[j][1] = input[i];

		for(int k=2; k<=output[j][0]; k++)
		{
			output[j][k] = output[row][k-1];
		}
		index++; 
		row++;
	}

	return smallOutput * 2;
}

int subset(int input[], int n, int output[][20]) {
    // Write your code here
	int size = helper(input,n,output,0);
	return size;
}
