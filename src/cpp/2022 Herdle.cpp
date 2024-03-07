//http://usaco.org/index.php?page=viewproblem2&cpid=1179
#include <bits/stdc++.h>
using namespace std;

int main() {
  char grid[3][3],guess[3][3];

  string s;
  int es[26]={0};
  for(int i=0;i<3;i++) {
    cin >> s;
    grid[i][0] = s[0];
    grid[i][1] = s[1];
    grid[i][2] = s[2];
    es[s[0]-'A']++;
    es[s[1]-'A']++;
    es[s[2]-'A']++;
  }
  for(int i=0;i<3;i++) {
    cin >> s;
    guess[i][0] = s[0];
    guess[i][1] = s[1];
    guess[i][2] = s[2];
  }
  int green=0;
  int yellow=0;
  
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      if (grid[i][j] == guess[i][j]) {
        green++;
        es[grid[i][j]-'A']--;
      }
    }
  }
  //we need to separate as two loops to check the yellows
  //since the gree may use all the elements
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      if (grid[i][j] != guess[i][j]) {
        if (es[guess[i][j]-'A']>0) {
        yellow++;
        es[guess[i][j]-'A']--;
      }
    }
  }
  }
  cout<<green<<endl;
  cout<<yellow;
}

/*
void solve() {
  string s[3];
  cin>>s[0]>>s[1]>>s[2];
  string r[3];
  cin>>r[0]>>r[1]>>r[2];
  int countA[26], countB[26];
  for(int i=0;i<26;i++)  {
    countA[i]=0;
    countB[i]=0;
  }
  int green=0, yellow=0;
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      if (s[i][j] == r[i][j]) {
        green++;
      }
      else {
        countA[s[i][j]-'A']++;
        countB[r[i][j]-'A']++;
      }
    }
  }

  for(int i=0;i<26;i++) {
    if (countB[i] > 0 && countA[i] > 0) {
      yellow += min(countB[i], countA[i]);
    }
  }
  
  cout<<green<<endl;
  cout<<yellow<<endl;
}
 
*/
