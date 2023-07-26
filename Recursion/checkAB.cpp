bool helper(char input[], int i)
{
	if(input[i] == '\0')
	return true;

	bool res = helper(input,i+1);

	if(res == false)
	return false;

	if(input[i] == 'a')
	{
		if(input[i+1] == 'a')
		return true;

		else if(input[i+1] == 'b' && input[i+2] == 'b')
		return true;

		else if(input[i+1] == '\0')
		return true;

		else
		return false;
	}

	else if(input[i] == 'b' && input[i+1] == 'b')
	{
		if(input[i+2] == '\0' || input[i+2] == 'a')
		return true;

		else return false;
	}

	return res;
}

bool checkAB(char input[]) {
	// Write your code here
	if(input[0] != 'a')
	return false;

	int i = 0;

	bool res= helper(input,i);
	return res;
}



