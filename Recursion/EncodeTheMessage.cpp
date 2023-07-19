#include <bits/stdc++.h> 
string encode(string &message)
{
    //   Write your code here.
    if (message.empty())
        return "";

    string result;
    int count = 1;

    for (int i = 1; i < message.length(); i++) {
        if (message[i] == message[i - 1])
            count++;
        else {
            result += message[i - 1];
            result += to_string(count);
            count = 1;
        }
    }

    // Add the last character and its count
    result += message.back();
    result += to_string(count);

    return result;
}
