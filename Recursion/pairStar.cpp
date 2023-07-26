// Change in the given string itself. So no need to return or print the changed string.

void helper(char input[], int size)
{
    if(size == 0 || size == 1)
        return;
    
    helper(input+1, size-1);
    
    if(input[0] == input[1])
    {
        int i = 0;
        
        while(input[i]!='\0')
            i++;
        
        for(int j=i-1; j>=1; j--)
            input[j+1] = input[j];
        input[1] = '*';
        
        input[i+1] = '\0';
    }
    
    return;
        
}

void pairStar(char input[]) {
    // Write your code here
    int i=0;
    
    while(input[i]!='\0')
        i++;
    
    helper(input,i);
    
    return;
}
