#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

void helper(string input, vector<string> &str, string temp) {
  if (input.length() == 0) {
    cout << temp << endl;
    return;
  }

  int digit1 = input[0] - '0';
  char ch = digit1 + 96;

  helper(input.substr(1), str, temp + ch);

  if (input.size() >= 2) {
    int digit2 = 10 * (input[0] - '0') + (input[1] - '0');
    if (digit2 > 26)
      return;

    char ch_double = digit2 + 96;

    helper(input.substr(2), str, temp + ch_double);
  }
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
vector<string> str;
helper(input,str,"");

return;
}

