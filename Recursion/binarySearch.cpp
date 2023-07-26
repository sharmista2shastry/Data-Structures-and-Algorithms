// input - input array
// size - length of input array
// element - value to be searched
int helper(int input[], int size, int element, int start, int end)
{
    if(size == 0)
    return -1;

    int mid = (start + end)/2;

    if(input[mid] == element)
    return mid;

    else if(input[mid] < element)
    helper(input,size/2,element,mid+1,end);

    else
    helper(input,size/2,element,start,mid-1);
}

int binarySearch(int input[], int size, int element) {
    // Write your code here
    int res = helper(input,size,element,0,size-1);
    return res;
}
