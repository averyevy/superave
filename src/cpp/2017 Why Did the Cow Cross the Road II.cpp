// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define IO(NAME) \
    cin.tie(0)->sync_with_stdio(0); \
    if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
    freopen(NAME ".out","w",stdout); 

#define log(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss);  cout<< "LOG - line:" << __LINE__<< "      "; err(_it, args); cout <<endl;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a <<"; ";
	err(++it, args...);
}


int main() {
  IO("circlecross");
  int S[26]={-1};
  int T[26]={-1};
  for(int i=0;i<26;i++) {
    S[i] = -1;
    T[i] = -1;
  }
  string ss;
  cin>>ss;
  for(int i=0;i<52;i++){
    if (S[ss[i]-'A'] == -1) {
      S[ss[i]-'A'] = i;
    }
    else {
      T[ss[i]-'A'] = i;
    }
  }
  int count = 0;
  for(int i=0;i<26;i++) {
   // cout<<S[i]<<":"<<T[i]<<endl;
    for(int j=0; j<26; j++) {
      if ( i != j ) {
        if ( S[i] < S[j] && T[i] > S[j] && T[i] < T[j] ) {
          count++;
        }
      }
      
    }
    
  }
  cout<<count;
  
}
