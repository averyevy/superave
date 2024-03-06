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
        //this is a pairwise comparsion, don't use cur[x] > cur[y]
        //a a more senior researcher never puts in more effort than a more junior researcher.
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


/***solution2**/
void solve() {
	int K,N;
    cin >> K >> N;
    string people[N+1];
    map<string,int> index;
    for(int i=1;i<N+1;i++) { 
        string s;
        cin >> s;
        people[i] = s;
        index[s] = i; 
    }
    string paper[K][N+1];
    
    for(int k=0;k<K;k++) {
        for(int i=1;i<N+1;i++) {
            cin>>paper[k][i];
        }
    }
    char ret[N+1][N+1];
    for(int i=0;i<N+1;i++) {
        for(int j=0;j<N+1;j++) {
            ret[i][j] = (i==j)? 'B' : '?';
        }
    }

    for(int t=0;t<K;t++) {
        for(int i = 1; i<N+1; i++) {
            bool transit = false;
            for(int j=i+1; j<N+1;j++) {
             //  log(i,j,paper[t][i], paper[t][j]);
                if (  paper[t][j-1] > paper[t][j] ) {
                    transit = true;
                }
                if ( transit) {
                    //j is more senior
                    string x = paper[t][i];
                    string y = paper[t][j];
                    ret[index[y]][index[x]] = '1';
                    ret[index[x]][index[y]] = '0';
                    //log(t,i,j,x, y);
                    //transit = true;
                }
                
            }
        }
    }
    for (int i=1;i<N+1;i++) {
        for (int j=1;j<N+1;j++) {
            cout<<ret[i][j];
        }
        cout<<endl;
    }

}
