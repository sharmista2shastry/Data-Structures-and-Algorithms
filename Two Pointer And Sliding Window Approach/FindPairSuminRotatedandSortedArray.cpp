/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    Where N is the number of elements in array
*/

bool findPairSum(vector<int> arr, int target)
{
    int n = arr.size();

    // Finding pivot element (sortest elements position)
    int low = 0;
    int high = n - 1;
    int pivot = 0;

    while(low <= high)
    {
        
        // To avoid the overflow
        int mid = (high - low) / 2 + low;
        
        // First case mid is largest element
        if(mid < high and arr[mid + 1] < arr[mid])
        {
            pivot = mid + 1;
            break;
        }
        
        // Mid is the smallest element
        if(mid > low and arr[mid - 1] > arr[mid])
        {
            pivot = mid;
            break;
        }
        
        // Deciding the side to search further
        // case when pivot is in right side
        if(arr[high] < arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    int st = pivot;
    
    // We will rotate as end may become less than 0
    int end = (n + pivot - 1) % n;
    
    // Using two pointer technique to find sum 
    while(st != end)
    {
        int temp = arr[st] + arr[end];

        if(temp == target)
        {
            return true;
        }
        else if(temp < target)
        {
            st = (st + 1) % n;
        }
        else
        {
            end = (n + end - 1) % n;
        }
    }
    return false;    
}
