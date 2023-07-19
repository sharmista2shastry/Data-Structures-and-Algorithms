// Change in the given string itself. So no need to return or print anything
#include <bits/stdc++.h>
using namespace std;

void replacePi(char input[]) {
	// Write your code here
	int n = strlen(input);

	if(n == 0 || n == 1)
	return;

	for(int i=0; i<n-1; i++)
	{
		if(input[i] == 'p' && input[i+1] == 'i')
		{
			input[i] = '3';
			input[i+1] = '.';
			for(int j=n; j>=i+2; j--)
			{
				input[j+2] = input[j];
			}
			input[i+2] = '1';
			input[i+3] = '4';
			i = i+3;
		}

		n = strlen(input);
	}

	
}


