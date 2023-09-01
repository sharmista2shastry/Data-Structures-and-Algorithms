int requiredCandies(vector < int > &students) {
    // Write your code here.
    int n = students.size(); //5
    vector<int> candies(n);
    int ans = 0;

    for(int i=0; i<n; i++)
    candies[i] = 1;         // [1 1 1 1 1]

    for(int i=1; i<n; i++)
    {
        if(students[i] > students[i-1])
        {
            if(candies[i] <= candies[i-1])
            candies[i] = candies[i-1] + 1;
        }
    }

    //[1 2 1 2 ]

    for(int i=n-2; i>=0; i--)
    {
        if(students[i] > students[i+1])
        {
            if(candies[i] <= candies[i+1])
            candies[i] = candies[i+1] + 1;
        }
    }

    for(int i=0; i<n; i++)
    ans += candies[i];

    return ans;
}
