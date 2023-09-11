void sort012(int *arr, int n)
{
    //Write your code here
    int zero = 0, one = 0, two = n-1;

    while(one <= two)
    {
        if(arr[one] == 0)
        {
            swap(arr[one], arr[zero]);
            one++;
            zero++;
        }

        else if(arr[one] == 1)
        one++;

        else
        {
            swap(arr[one], arr[two]);
            two--;
        }
    }
}
