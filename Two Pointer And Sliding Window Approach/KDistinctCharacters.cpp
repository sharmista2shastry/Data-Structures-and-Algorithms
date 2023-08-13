#include <bits/stdc++.h>

int getLengthofLongestSubstring(int k, string s)
{
   // Write your code here.
   int n = s.length();

   if(n <= k)
   return n;

   int p1 = 0, p2 = 1, count = 0;
   int maxCount = INT_MIN;
   vector<int> freq(26);

   for(int i=0; i<26; i++)
   freq[i] = 0;

   freq[s[p1]-'a']++;
   count++;

   while(p2 < s.length())
   {
      if(count < k && (freq[s[p2]-'a']) == 0)
      {
         freq[s[p2]-'a']++;
         count++;
         maxCount = max(maxCount, p2-p1+1);
         p2++;
      }

      else if(count <= k && freq[s[p2]-'a'] > 0)
      {
         freq[s[p2]-'a']++;
         maxCount = max(maxCount, p2-p1+1);
         p2++;
      }

      else
      {
         freq[s[p2] - 'a']++;
         count++;

         while(count > k)
         {
            freq[s[p1]-'a']--;
            if(freq[s[p1]-'a'] == 0)
            count--;
            p1++;
         }
         maxCount = max(maxCount, p2-p1+1);
         p2++;
      }
   }

   return maxCount;
}
