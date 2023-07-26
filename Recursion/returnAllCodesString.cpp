#include <string.h>
#include<iostream>
#include<vector>
using namespace std;

void helper(string input, vector<string> &str, string temp)
{
    if(input.length () == 0)
    {
        str.push_back(temp);
        return;
    }

    int digit1 = input[0] - '0';
    char ch = digit1 + 96;

    helper(input.substr(1),str,temp+ch);

    if(input.size() >= 2)
    {
        int digit2 = 10 * (input[0] - '0') + (input[1] - '0');
        if(digit2 > 26)
        return;

        char ch_double = digit2 + 96;

        helper(input.substr(2),str,temp+ch_double);
    }

}

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. DonÃÂÃÂ¢ÃÂÃÂÃÂÃÂt print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    vector <string> str;

    helper(input,str,"");

    for(int i=0; i<str.size(); i++)
    {
        output[i] = str[i];
    }

    int res = str.size();

    return res;
}

