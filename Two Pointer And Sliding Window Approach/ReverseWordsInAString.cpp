#include <bits/stdc++.h>
using namespace std;

string reverseString(string &str){
	// Write your code here.
	int end = str.length()-1;	
	string final = "";

	while(str[end] == ' ')
	end--;

	while(end >= 0)
	{
		int j = end;

		while(str[end] != ' ' && end >= 0)
		end--;

		string word = "";
		word += str.substr(end+1, j-end);

		if(end > 0)
		word += " ";

		final += word;
		
		while(str[end] == ' ')
		end--;
	}

	return final;
}
