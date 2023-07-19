bool helper(string str, int start, int end)
{
    if(start >= end)
    return true;

    if(str[start] != str[end])
    return false;

    return helper(str, start+1, end-1);
}

bool isPalindrome(string& str) {
    // Write your code here.
    if(str.length() == 0 || str.length() == 1)
    return true;

    return helper(str, 0, str.length() - 1);
}
