/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

DonÃ¢ÂÂt print the subsets, just save them in output.
***/
int index = 0;

void helper(int input[], int n, int output[][50], int temp[], int k, int si, int tempsize)
{
	if(n == 0)
	{
		if(k == 0)
		{
			output[index][0] = tempsize;

			for(int i=0; i<tempsize; i++)
			{
				output[index][i+1] = temp[i];			
			}
			index++;
		}

		return;
	}

	helper(input, n-1, output, temp, k, si+1, tempsize);

	temp[tempsize] = input[si];

	helper(input, n-1, output, temp, k-input[si], si+1, tempsize+1);
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
	int temp[50];

	helper(input,n,output,temp,k,0,0);
	
	return index;
}
