/*
	To apply the method explained in the hint video, we have to add two more parameters in the function call. This can be done by calling a helper function from given function. The helper function can have three parameters: array, start index, end index.  
	
	Skeleton code to achieve this:
	#include <iostream>
	using namespace std;
	
	void partition(int input[], int start, int end)
	{
    		// your code goes here 
	}
	void quickSort(int input[], int size)
	{
    		partition(input, 0, size - 1);
	}
		
*/

int partition(int input[], int start, int end)
{
	int pi;
	int count = 0;

	for(int i=start+1; i<=end; i++)
	{
		if(input[i] <= input[start])
			count++;
	}

	pi = count + start;

	int temp = input[start];
	input[start] = input[pi];
	input[pi] = temp;

	int i=start, j=end;

	while(i<=j)
	{
		if(pi == i)
		i++;

		else if(input[i] <= input[pi])
		i++;

		else if(input[j] > input[pi])
		j--;

		else
		{
			int temp = input[i];
			input[i] = input[j];
			input[j] = temp; 
			i++;
			j--;
		}
	}
	return pi; 
}

void helper(int input[], int start, int end)
{
	if(start >=end)
	return;

	int c = partition(input, start, end);

	helper(input, start, c-1);

	helper(input, c+1, end);

	return;
}


void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */

	helper(input, 0, size-1);
	return;
}
