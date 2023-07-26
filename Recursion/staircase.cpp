
int staircase(int n){
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    if(n == 0)
    return 1;

    int w1 = 0, w2 = 0, w3 = 0;

    if(n-1 >= 0)
    w1 = staircase(n-1);

    if(n-2 >= 0)
    w2 = staircase(n-2);

    if(n-3 >= 0)
    w3 = staircase(n-3);

    int res = w1 + w2 + w3; 

    return res; 
}
