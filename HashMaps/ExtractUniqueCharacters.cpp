#include <unordered_map>

string uniqueChar(string str) {
	// Write your code here
	unordered_map<char,int> freq;
	string res = "";
	for(int i=0; i<str.length(); i++)
	{
		freq[str[i]]++;

          if (freq[str[i]] <= 1) 
		  {
            res += str[i];
          }
    }

	return res;
}
