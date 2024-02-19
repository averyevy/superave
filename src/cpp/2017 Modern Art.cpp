#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

double PI = 4*atan(1);

#define IO(NAME) \
    cin.tie(0)->sync_with_stdio(0); \
    if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
    freopen(NAME ".out","w",stdout); 


template<template <typename> class P = std::less > 
struct compare_pair_second { 
    template<class T1, class T2> bool operator()(const std::pair<T1, T2>& left, const std::pair<T1, T2>& right) {
        return P<T2>()(left.second, right.second);
    }
};

#define log(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss);  cout<< "LOG - line:" << __LINE__<< "      "; err(_it, args); cout <<endl;}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a <<"; ";
  err(++it, args...);
}

const ll inf = 1e18;

#define MAX_N 10

int N;
int B[MAX_N][MAX_N];

bool color_appears(int c) {
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
        if (B[i][j] == c ) {
          return true;
        }
    }
  }
  return false;
}

bool on_top_of(int c1, int c2) {
  int top=N, bottom=0, left=N, right=0;
  for (int i=0; i < N; i ++) {
    for (int j=0; j < N; j ++) {
      if ( B[i][j] == c2 ) {
        top = min(top, i);
        bottom = max(bottom, i);
        left = min(left, j);
        right = max(right, j);
      }
    }  
  }
  for(int i=top; i <= bottom; i ++ ) {
    for(int j=left; j <= right; j ++) {
      if (B[i][j] == c1) return true;
    }
  }
  return false;
}



 
int main(){
  IO("art");
  cin >> N;
  for(int i=0;i<N;i++) {
    string s;
    cin >> s;
    for( int j=0; j <N; j ++ ) {
      B[i][j] = s[j] - '0';
    }  
  }

  int answer = 0;
  for(int i=1; i <=9 ; i ++) {
    if (color_appears(i)) {
      bool first = true;
      for (int j = 1; j <=9 ; j++) {
        if ( i!=j && color_appears(j) && on_top_of(i,j)) {
          first = false;
        }
      }
      if (first) answer++;
    }
  }
  cout<< answer <<endl;
};
