void heapify(int *arr, int n)
{
   for(int i=1; i<n; i++)
   {
       int childIndex = i;
       int parentIndex = (childIndex-1)/2;

       if(arr[childIndex] > arr[parentIndex])
       continue;

       while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (arr[childIndex] < arr[parentIndex]) {
                int temp = arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
   }
}

void heapSort(int arr[], int n) {
    // Write your code
    heapify(arr,n);

      while(n > 0)
      {
          int temp = arr[0];
          arr[0] = arr[n-1];
          arr[n-1] = temp;

          n--;

          int leftChild, rightChild, parentIndex;

          parentIndex = 0;
          leftChild = 2*parentIndex + 1;
          rightChild = 2*parentIndex + 2;
          int maxIndex;

          while(leftChild < n)
          {
            if (leftChild < n && rightChild < n)
                maxIndex = (arr[leftChild] <= arr[rightChild]) ? leftChild : rightChild;

            else if (leftChild < n && arr[leftChild] < arr[parentIndex])
                maxIndex = leftChild;
                
            else
                break;

            if(arr[maxIndex] < arr[parentIndex])
            {
                int temp = arr[maxIndex];
                arr[maxIndex] = arr[parentIndex];
                 arr[parentIndex] = temp;
            }
              
              parentIndex = maxIndex;
              leftChild = 2*parentIndex + 1;
              rightChild = 2*parentIndex + 2;
          }
      }
}
