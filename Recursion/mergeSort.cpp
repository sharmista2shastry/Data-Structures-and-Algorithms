void helper(int input[],int start, int end)
{
    if(start >= end)
        return;
    
    int mid = (start + end)/2;
    
    helper(input,start,mid);
    
    helper(input,mid+1,end);

    int i = start; 
    int j = mid + 1; 
    int k = start;

    int output [1000]; 

    while(i <= mid && j <= end)
    {
        if(input[i] < input[j])
            output[k++] = input[i++];
        else if (input[i] == input[j])
        {
            if(i != j)
            {
                output[k++] = input[i++];
                output[k++] = input[j++];
            }

            else
            {
                output[k++] = input[i];
                i++;
                j++;
            }
        }
        else
            output[k++] = input[j++];
    }

    while(i > mid && j <= end)
    {
        output[k++] = input[j++];
    }

    while(i <= mid && j>end)
    {
        output[k++] = input[i++];
    }
    
    i = start;

    while(i <= end)
    {
        input[i] = output[i];
        i++;
    }

    return;
}

void mergeSort(int input[], int size){
	// Write your code here
    helper(input,0,size-1);
    
    return; 
}
