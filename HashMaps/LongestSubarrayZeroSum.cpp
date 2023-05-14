#include <unordered_map>

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    int sum = 0, len = 0, maxlen = 0;
    unordered_map<int, int> sumIndex;

   for(int i=0; i<n; i++)
   {
       sum += arr[i];

       if(sumIndex.count(sum) > 0)
       {
           if(sum == 0)
           len = i - (sumIndex[sum] - 1) + 1;

           else
           len = i - sumIndex[sum];
       }

       if(len > maxlen)
       maxlen = len;

       if(sumIndex.count(sum) <= 0)
       sumIndex[sum] = i;
   }

   if(sumIndex[0] + 1 > maxlen)
   return sumIndex[0] + 1;

   return maxlen;
}
