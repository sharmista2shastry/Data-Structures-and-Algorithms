#include <string>
#include<cmath>
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

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num == 0 || num == 1)
    return 1;

    int res = keypad(num/10,output);
    int digit = num % 10;

    string str = dial(digit);
    int k = 0; 

    for(int i=0; i<str.length(); i++)
    {
        for(int j=0; j<res; j++)
        {
            if(i == 0)
            output[k++] += str[i];

            else
            output[k++] = output[j].substr(0,output[j].length()-1) + str[i];
        }
    }

    return res * str.length();
}
