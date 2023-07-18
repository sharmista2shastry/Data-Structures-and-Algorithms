#include<iostream>
#include<algorithm>
using namespace std;

void convert(int n, string &str)
{
    if(n == 0)
    return;

    int remainder = n % 2;
    char ch = remainder + '0';
    str += ch;

    convert(n/2, str);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    string str;

    convert(n, str);
    reverse(str.begin(), str.end());

    cout << str << endl;

    return 0;
}
