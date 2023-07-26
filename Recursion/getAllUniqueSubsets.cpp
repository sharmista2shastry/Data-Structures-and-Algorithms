
void helper(int input[], int size, int output[], int si, int outsize)
{
	if(size ==si)
	{
		for(int i=0; i<outsize; i++)
		cout << output[i] << " ";

		cout << endl;
		return;
	}

	helper(input,size,output,si+1,outsize);

	int new_output[1000];
	for(int i=0; i<outsize; i++)
	new_output[i] = output[i];
	new_output[outsize] = input[si];

	helper(input,size,new_output,si+1,outsize+1);
}

void printSubsetsOfArray(int input[], int size) {
	// Write your code here
	int output[1000];
    helper(input,size,output,0,0);

	return;
}
