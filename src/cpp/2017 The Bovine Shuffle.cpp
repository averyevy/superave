//http://www.usaco.org/index.php?page=viewproblem2&cpid=760

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

bool cow_infected[101];
int N, cowx[251], cowy[251];

int main() {
    IO("shuffle");
    int N;
    cin>>N;
    int s[N+1];
    for(int i=1;i<=N;i++){
        cin>>s[i];
    }
    string ret[N+1];
    

    for(int i=1;i<=N;i++){
        cin>>ret[i];
    }
    
    string newret[N+1];
    string tmp[N+1];
    for(int iter=0;iter<3;iter++) {
        for(int i=1;i<=N;i++) {
            newret[i] = ret[s[i]];
        }
        for(int i=1;i<=N;i++){
            ret[i] = newret[i];
        }
    }
    
    for(int i=1;i<N;i++) {
        cout<< newret[i] << endl;
    }
    cout<<newret[N];
    return 0;
}
