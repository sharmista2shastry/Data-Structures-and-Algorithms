int sumOfDigits(int n) {
    // Write your code here
    if(n <= 0)
    return 0;

    int last = n % 10;

    return last + sumOfDigits(n/10);
}
