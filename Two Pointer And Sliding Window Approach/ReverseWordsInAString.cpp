#include <bits/stdc++.h>

void removeSpaces(string &str)
{
	int readIdx = 0, writeIdx = 0;
	bool spaceEncountered = false;

	while(str[readIdx] == ' ')
	readIdx++;

	while(readIdx < str.length())
	{
		if(str[readIdx] != ' ')
		{
			str[writeIdx] = str[readIdx];
			writeIdx++;
			spaceEncountered = false;
		}

		else if(!spaceEncountered)
		{
			str[writeIdx] = str[readIdx];
			writeIdx++;
			spaceEncountered = true;
		}

		readIdx++;
	}

	if(str[writeIdx-1] == ' ')
	writeIdx--;
	str.resize(writeIdx);
}

string reverseString(string &str){
	// Write your code here.
	removeSpaces(str);
	reverse(str.begin(), str.end());

	int start = 0;

	while(start < str.length())
	{
		int i = start;

		while(start < str.length() && str[start] != ' ')
		start++;

		reverse(str.begin()+i, str.begin()+start);

		start++;
	}

	return str;
}
