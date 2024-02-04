//https://ide.usaco.guide/NpIKk6TP6KW75URln9X
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


long solve(int dist, int minspeed) {
    int ldist = 0;
    int rdist = 0;
    int timeused = 0;
    
    int curspeed = 1;
    while( ldist + rdist < dist) {
        ldist += curspeed;
        timeused++;
        if ( ldist + rdist >= dist) return timeused;
        if ( curspeed >= minspeed) {
            rdist += curspeed;
            timeused++;
            if ( ldist + rdist >= dist) return timeused;
        }
        curspeed++;
    }
    
}

int main() {
    IO("race");
    int K,N;
    cin>>K>>N;

    for(int i=0;i<N;i++) {
        int s;
        cin >> s;
        cout << solve(K,s) <<endl;
    }
    return 0;
}
