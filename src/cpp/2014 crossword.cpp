//http://usaco.org/index.php?page=viewproblem2&cpid=488

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
    IO("crosswords");
    int M,N;
    cin>>M>>N;
    char grid[M][N];

    for(int i=0;i<M;i++) {
        string s;
        cin>>s;
        for(int j=0;j<N;j++) { 
            grid[i][j]=s[j];
        }
    }
    vector<pair<int,int>> ret;

    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) { 
            bool horizontal = 
            ( grid[i][j] == '.' &&  j < N-2 && grid[i][j+1] == '.' && grid[i][j+2] == '.'
            && ( j == 0 || grid[i][j-1] == '#') );
            bool vertical = 
            ( grid[i][j] == '.' &&  i < M-2 && grid[i+1][j] == '.' && grid[i+2][j] == '.'
            && ( i == 0 || grid[i-1][j] == '#') );
            
            if (horizontal || vertical) {
                ret.pb(mp(i+1,j+1));
            }
                 
        }
    } 

    cout << ret.size() <<endl;
    for(auto p : ret) {
        cout<<p.f <<" "<< p.s<<endl;
    }
    return 0;
}
