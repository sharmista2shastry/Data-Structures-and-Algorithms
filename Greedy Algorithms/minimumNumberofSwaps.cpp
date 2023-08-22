#include <bits/stdc++.h>
using namespace std;

int minSwap (int N, int M, int K, string &S, vector<char> &arr)
{
    // Write your code here.
    int swap = 0;
    int *freqArray = new int[26];
    int **freqString = new int*[K];

    for(int i=0; i<26; i++)
    freqArray[i] = 0;

    for(int i=0; i<M; i++)
    freqArray[arr[i]- 'a']++;

    for(int i=0; i<K; i++)
    {
        freqString[i] = new int[26];
        for(int j=0; j<26; j++)
        {
            freqString[i][j] = 0;
        }
    }

    for(int i=0; i<K; i++)
    {
        int index = i;
        int maxFreq = 0;
        int totalFreq = 0;
        while(index < N)
        {
            freqString[i][S[index] - 'a']++;
            if(freqArray[S[index] - 'a'] > 0)
            maxFreq = max(maxFreq, freqString[i][S[index] - 'a']);
            index += K;
        }

        for(int j=0; j<26; j++)
        {
            totalFreq += freqString[i][j];
        }
    
        swap += totalFreq - maxFreq;
    }

    return swap;
}
