int d = 1;

int countZeros(int n) {
    // Write your code here
    if(n == 0 && d > 1)
        return 0;
    
    d++;
    int ans = countZeros(n/10);
    
    if(n % 10 == 0)
        return ans + 1;
    
    return ans; 
}


