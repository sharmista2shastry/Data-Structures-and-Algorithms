#include <bits/stdc++.h>

void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/

	for(int i=0; i<strlen(input); i++)
	{
		int j  = i+1;
		while(input[i] == input[j])
		{
			j++;
		}

		if(j >= strlen(input))
		{
			input[i+1] = '\0';
			break;
		}

		int start = i+1;

		for(int k=j; k<strlen(input); k++)
		{
			input[start++] = input[k];
		}
	}
}
