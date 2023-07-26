vector<long long> createSequence(long long n){
    // Write your code here.
    vector<long long> ans;

    if(n < 2)
    return ans;

    if(n >= 2 && n < 5)
    ans.push_back(2);

    else
    {
        ans.push_back(2);
        ans.push_back(5);
    }

   for(long long i=0; i < ans.size(); i++)
   {
       long num1 = (ans[i] * 10) + 2;
       long num2 = (ans[i] * 10) + 5;

       if(num1 > n)
       break;

       if(num2 > n)
       break;

       ans.push_back(num1);
       ans.push_back(num2);
   }

   return ans;
}
