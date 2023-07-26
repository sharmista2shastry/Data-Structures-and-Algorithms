#include <string>
using namespace std;

int helper(string input, string output[], string temp[])
{
	if(input.length() == 0)
	{
		temp[0] = "";
		return 1;
	}

	int res = helper(input.substr(1),output,temp);

	int len = input.length();

	int index = 0;

	for(int i=0; i<res; i++)
	{
		string str = output[i];
		for(int j=0; j<=str.length(); j++)
		{
			temp[index++] = str.substr(0,j) + input[0] + str.substr(j);
		}
	}

	for(int i=0; i<res*len; i++)
	output[i] = temp[i];

	return res * len;
}

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
	string temp[10000];
	int res = helper(input,output, temp);

	return res;
}
