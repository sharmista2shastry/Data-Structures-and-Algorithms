int findMinCost(int n, vector<vector<int>> &cost)
{
	// Write your code here.
	int totalCost = 0;
	vector<int> sendAtoB (2*n);

	for(int i=0; i<2*n; i++)
	{
		totalCost += cost[i][0];
		sendAtoB[i] = cost[i][1] - cost[i][0];
	}

	sort(sendAtoB.begin(), sendAtoB.end());

	for(int i=0; i<n; i++)
	totalCost += sendAtoB[i];

	return totalCost;
}
