int multiplyNumbers(int m, int n) {
    // Write your code here
    if(n == 0)
        return 0;
    int ans = m + multiplyNumbers(m,n-1);
    
    return ans; 
}


