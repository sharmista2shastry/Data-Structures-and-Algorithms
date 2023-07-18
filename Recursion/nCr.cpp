#include<iostream>
using namespace std;

int factorial(int n)
{
    if(n == 1 || n == 0)
    return 1;

    return factorial(n-1) * n;
}

int main()
{
    int n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;

    int num = factorial(n);
    int den1 = factorial(n-r);
    int den2 = factorial(r);

    cout << num / (den1 * den2) << endl;

    return 0;
}
