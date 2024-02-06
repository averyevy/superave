//http://www.usaco.org/index.php?page=viewproblem2&cpid=1132
//The key part is to understand the rules.

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  string p[K];
  char result[K][K];
  for( int i = 0; i < K; i ++) {
    for( int j = 0; j < K; j ++) {
      if (i!=j) {
        result[i][j] = '?';
      }
      else {
        result[i][i] = 'B';
      }
    }
    }
    
  map<string, int> data;
  for(int i=0;i<K; i++) {
    cin >> p[i];
    data[p[i]] = i;
  }
  
  string cur[K];
  for(int i=0;i<N;i++) {
    for(int j=0;j<K; j++) {
      cin >> cur[j];
    }

    for(int x=0;x<K;x++) {
      bool alphaOrder = true;
      for(int y=x+1;y<K;y++) {
        if (cur[y-1]>(cur[y]) ) {
          alphaOrder = false;
        }
        if (!alphaOrder) {
          int a = data[cur[x]], b = data[cur[y]];
          result[a][b] = '0';
          result[b][a] = '1';
        }
      }
    }   
  }
  
  for(int i=0;i<K;i++) {
    for(int j=0;j<K;j++) {
      cout<<result[i][j];
    }
    cout<<endl;
  }
}
