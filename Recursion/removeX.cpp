// Change in the given string itself. So no need to return or print anything

void helper(char input[], int size)
{
    if(size == 0)
        return; 
    
    helper(input+1,size-1);
    
    if(input[0] == 'x')
    {
        int j;
        
        for(j=1; j<size; j++)
            input[j-1] = input[j];
        
        input[j-1] = '\0';
    }
    
    return;
}

void removeX(char input[]) {
    // Write your code here
    int i = 0;
    
    while(input[i]!='\0')
        i++;
    
    helper(input,i);
    
    return;
}
