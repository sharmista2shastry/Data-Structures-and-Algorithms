#include <iostream>
using namespace std;

void pyramid(int n, int i)
{
    if(n == 0)
    return;

    for(int count=0; count<n-1; count++)
    cout << ' ';

    for(int count=0; count < (2*i)-1; count++)
    cout << "*";

    for(int count=0; count<n-1; count++)
    cout << ' ';

    cout << endl;

    pyramid(n-1, i+1);
}

int main()
{
    int n; 
    cout << "Enter a number: ";
    cin >> n;
    pyramid(n, 1);

    return 0;
}
