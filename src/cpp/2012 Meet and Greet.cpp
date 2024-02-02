
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
    IO("greetings");
    int b, e;
    cin >> b >> e;
   
    vector<int> B,E;

    int s=0,cb=0,ce=0;
    B.pb(s);
    forn(i,b){ 
        int u; char d;
        cin >> u>>d;
        for(int j=0;j<u;j++) {
            cb++;
        if (d=='L'){ s--;
        }
        else { s++; }
         B.pb(s);
        }
    };
    //for(auto v:B) {log(v);}

    s=0;
    E.pb(s);
    forn(i,e){ 
        int u; char d;
        cin >> u>>d;
        for(int j=0;j<u;j++) {
            ce++;
        if (d=='L'){ s--;
        }
        else { s++; }
         E.pb(s);
        }
    };
    //for(auto v:E) {log(v);}
    //log(cb,ce);
    int count =0;
    int ti = min(cb, ce);
   
    if ( cb < ce ) {
        while ( B.size() < E.size()) {
            B.pb(B[B.size()-1]);
        }
    }else {
        while ( B.size() > E.size()) {
            E.pb(E[E.size()-1]);
        }
    }
    forn(i,B.size()) { 
            if (B[i] == E[i] && B[i-1]!=E[i-1]) {
               // log(i);
                count++;
            }
        }
    
    cout << count;
    
    return 0;
}
