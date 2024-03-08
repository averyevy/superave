//http://usaco.org/index.php?page=viewproblem2&cpid=1205

#include <bits/stdc++.h>
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
 
const int MOD = 1000000007;
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



void solve2() {
  int n;
	cin >> n;
  string s1,s2,s3,s4;
  cin>>s1>>s2>>s3>>s4;
 // cout<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl;

  set<string> words;
  for(int i1=0; i1<7;i1++) {
    for(int i2=0; i2<7;i2++) {
      for(int i3=0; i3<7;i3++) {
        for(int i4=0; i4<7;i4++) {
            string s;
            if (i1 < 6)  s +=  s1[i1];
            if (i2 < 6)  s +=  s2[i2];
            if (i3 < 6)  s +=  s3[i3];
            if (i4 < 6)  s +=  s4[i4];
            if (s.length() >=1) {
              sort(s.begin(), s.end());
              words.insert(s);
            }
            
        }
      }
    }
  }
  //for (auto s: words){ cout<<s<<endl;}
  
  for (int i=0;i<n;i++) {
    string t;
    cin>>t;
    sort(t.begin(),t.end());
    cout<< ((words.count(t) >0 ) ? "YES" : "NO");
    if (i<n-1) cout<<endl;
  }
  
  
}

bool solve(array<string, 4> blocks) {
    string word;
    cin >> word;
   
    do {
        bool ok = true;
        for(int i=0;i<word.size();i++) {
            if (find(blocks[i].begin(), blocks[i].end(), word[i]) == blocks[i].end()) ok = false;
        }
        if (ok) return true;
    } while (next_permutation(blocks.begin(), blocks.end()));
	return false;
}

int main() {
    //IO("hps");
    int N;
    cin>>N;
    array<string,4> blocks;
    for(int i=0; i<4; i++) cin>>blocks[i];
    sort(blocks.begin(), blocks.end());
    for(int i=0; i <N; i ++ ) {
    bool b = solve(blocks);
    if (b) cout << "YES" << endl;
    else cout << "NO" <<endl;
    }
    return 0;
}
