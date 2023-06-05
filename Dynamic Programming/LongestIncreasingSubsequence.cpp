//Time Complexity: O(n^2)

int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
	int *output = new int[n];

	output[0] = 1;

	for(int i=1; i<n; i++)
	{
		output[i] = 1;

		for(int j=i-1; j>=0; j--)
		{
			if(arr[j] >= arr[i])
			continue;
		
			int count = 1 + output[j];

			if(count > output[i])
			output[i] = count;
		}
	}

	int best = 0;

	for(int i=0; i<n; i++)
	{
		if(best < output[i])
		best = output[i];
	}

	delete [] output;
	return best;
}
