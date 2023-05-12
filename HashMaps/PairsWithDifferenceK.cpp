#include <unordered_map>

int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
	int count = 0;
	unordered_map<int, int> visited;

	for(int i=0; i<n; i++)
	visited[arr[i]]++;

	for(int i=0; i<n; i++)
	{
		if(visited[arr[i]] == -1)
		continue;

		if(k == 0)
		{
			int freq = visited[arr[i]];
			count += ((freq-1)*freq)/2;
			if(k != 0)
			visited[arr[i]+k] = -1;
		}

		else
		{
			if(visited.count(arr[i] + k) > 0)
			{
				count++;
				visited[arr[i]+k] = -1;
			}

			if(visited.count(arr[i] - k) > 0)
			{
				count++;
				visited[arr[i]-k] = -1;
			}
		}
            
		 visited[arr[i]] = -1;
    }

	return count;
}
