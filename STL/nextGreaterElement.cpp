#include <vector>
#include <stack>

vector<int> nextGreaterElement(vector<int> input) {
	// Write your code here
	int n = input.size();
	vector<int> arr(n);
	stack<int> s;

	arr[n-1] = -1;

	for(int i = n-1; i >= 0; i--)
	{
		if(!s.empty() && input[i] < s.top())
		{
			arr[i] = s.top();
		}

		else if(!s.empty() && input[i] >= s.top()){
			while(!s.empty() && input[i] >= s.top())
			{
				s.pop();
			}

			if(s.empty())
			arr[i] = -1;

			else
			arr[i] = s.top();
		}

		s.push(input[i]);
	}

	return arr;
}
