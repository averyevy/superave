
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


int main() {
    IO("word");
    int N,K;
    cin>>N>>K;
   
    vector<string> ss;
    for(int i=0;i<N;i++) {
        string s;
        cin>>s;
        ss.push_back(s);
     //   log(s);
    }
    
    string w = ss[0];
    int len = w.length();
    for(int i=1; i<ss.size(); i ++) { 
        if (len + ss[i].length() > K) {
            cout<< w << endl;   
            w = ss[i];
            len = ss[i].length();
        } 
        else {
            w += " "+ ss[i] ;
            len += ss[i].size();
        }
    }
    cout << w;
    return 0;
}
