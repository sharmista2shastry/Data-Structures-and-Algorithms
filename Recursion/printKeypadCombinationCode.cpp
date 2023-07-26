#include <iostream>
#include <string>
using namespace std;

string dial(int key)
{
    string val[10];
    val[0] = "";
    val[1] = "";
    val[2] = "abc";
    val[3] = "def";
    val[4] = "ghi";
    val[5] = "jkl";
    val[6] = "mno";
    val[7] = "pqrs";
    val[8] = "tuv";
    val[9] = "wxyz";

    return val[key];
}

void helper(int num, string output)
{
    if(num == 0 || num == 1)
    {
        cout << output << endl;
        return;
    }

    int digit = num % 10;
    string str = dial(digit);

    for(int i=0; i<str.length(); i++)
    helper(num/10,str[i]+output);
    
    return;
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output = "";
    helper(num,output);

    return;
}
