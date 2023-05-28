#include <bits/stdc++.h>
using namespace std;

vector<string> split(string str, char delimiter) { 
  vector<string> internal; 
  stringstream ss(str); // Turn the string into a stream. 
  string tok; 
 
  while(getline(ss, tok, delimiter)) { 
    internal.push_back(tok); 
  } 
 
  return internal; 
}

vector<string> checkHorizontal(vector<string> input, string word, int i, int j) {
  for(int k = 0; k < word.size(); k++) {
    if(input[i][j + k] == '-' || input[i][j + k] == word[k]) input[i][j + k] = word[k];
    else {
      input[i][j] = '-';
      return input;
    }
  }
  return input;
}

vector<string> checkVertical(vector<string> input, string word, int i, int j) {
  for(int k = 0; k < word.size(); k++) {
    if(input[i + k][j] == '-' || input[i + k][j] == word[k]) input[i + k][j] = word[k];
     else {
        input[i][j] = '-';
        return input;
      }
    }
    return input;
}

void crossword(vector<string>input, vector<string> c, int word) {
  if(word == c.size()) {
    for(int i = 0; i < 10; i++) {
      cout<<input[i]<<endl;
    }
    
    return;
  } 

  string curr = c[word];
  int maxLen = 10 - curr.size();
  
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j <= maxLen; j++) {
      vector<string> temp = checkHorizontal(input, curr, i, j);
      if(temp[i][j] != '-') {
        crossword(temp, c, word + 1);
      }
    }
  }
  
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j <= maxLen; j++) {
      vector<string> temp = checkVertical(input, curr, j, i);
      if(temp[j][i] != '-') {
        crossword(temp, c, word + 1);
      }
    }
  }
}

int main() 
{
    vector<string> input(10);
    
    for(int i = 0; i < 10; i++) {
      cin>>input[i];
    }
    
    string s;
    cin>>s;
    vector<string> c = split(s, ';');
    
    crossword(input, c, 0);
    
    return 0;
}
