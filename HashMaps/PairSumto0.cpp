#include<unordered_map>

int pairSum(int *arr, int n) {
	// Write your code here
	int count = 0;
	int count0 = 0;
	unordered_map<int, int> freq;

	for(int i = 0; i < n; i++)
	{
		freq[arr[i]]++;
		if(arr[i] != 0 && freq.count(arr[i] * -1) > 0)
		count += freq[arr[i] * -1];

		else if(arr[i] == 0)
		count0 ++;
	}

	if(count0 > 1)
	{
		count += (count0 * (count0 -1))/2;
	}

	return count;
}
