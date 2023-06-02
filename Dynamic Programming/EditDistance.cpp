//Using Brute Force
//Time complexity: O(3^n), where n is the length of both the input strings

int helper(string s1, string s2, int len1, int len2)
{
	if(len1 == 0)
	{
		return len2;
	}

	if(len2 == 0)
	{
		return len1;
	}

	if(s1[0] == s2[0])
	return helper(s1.substr(1), s2.substr(1), len1-1, len2-1);

	int i = 1+ helper(s1.substr(1), s2, len1-1, len2);
	int d = 1+ helper(s1, s2.substr(1), len1, len2-1);
	int r = 1+ helper(s1.substr(1), s2.substr(1), len1-1, len2-1);

	return min(i, min(d, r));
}

int editDistance(string s1, string s2) {
	// Write your code here
	return helper(s1, s2, s1.length(), s2.length());
}

