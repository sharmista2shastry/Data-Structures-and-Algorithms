#include <iostream>
#include <string>
using namespace std;

void helper(string input, string output) {
  if (input.length() == 0) {
	cout << output << endl;  
    return;
  }

  int len = input.length();

  for(int i=0; i<len; i++)
  {
	  string str ="";
	  for(int j=0; j<len; j++)
	  {
		  if(i != j)
		  str += input[j];
	  }

	  helper(str,output+input[i]);
  }

}

void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
	helper(input,"");
	return;
}
