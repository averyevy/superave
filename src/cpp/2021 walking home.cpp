//http://www.usaco.org/index.php?page=viewproblem2&cpid=1157
/*The key points of this problem is how to iterate the path with K =1, K=2, K=3*/
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

int INF = 1000000001;


void solve() {
    int M,N;
    cin >>M >>N;
    //log(M, N);
    char grid[M][M];
    for(int i=0;i<M;i++){
        string s;
        cin >>s;
        for(int j=0;j<M;j++) {
            grid[i][j]=s[j];
        }
    }

    //N =1 
    int route = 0;
    bool safe = true;
    for(int i=0;i<M;i++){
        if (grid[0][i] == 'H') {
            safe = false;
            break;
        }
        if (grid[i][M-1] == 'H') {
            safe = false;
            break;
        }
    }
    if (safe) route++;
    safe = true;
    for(int i=0;i<M;i++){
        if (grid[i][0] == 'H') {
            safe = false;
            break;
        }
        if (grid[M-1][i] == 'H') {
            safe = false;
            break;
        }
    }
    if (safe) route++;

    if ( N >= 2) {
        for( int j = 1; j < M-1; j ++) {
            safe = true;
            for (int a = 0; a < j; a++) {
                if (grid[0][a] == 'H') { 
                    safe = false;
                }
            }

            for (int a = 0; a < M; a++) {
                if (grid[a][j] == 'H') safe = false;
            }
                
            for (int a = j; a < M; a++) {
                if (grid[M-1][a] == 'H') safe = false;
            }
            if (safe) route++;
        }

        for( int i = 1; i < M-1; i ++) {
            safe = true;
                for (int a = 0; a < i; a++) {
                    if (grid[a][0] == 'H') safe = false;
                }

                for (int a = 0; a < M; a++) {
                    if (grid[i][a] == 'H') safe = false;
                }
                    
                for (int a = i; a < M; a++) {
                    if (grid[a][M-1] == 'H') safe = false;
                }
                if (safe) route++;
        }
    }
    //N=3

  if ( N >= 3) {
    for( int i = 1; i< M-1; i++) {
        for( int j = 1; j < M-1; j ++) {
              safe = true; 
              if ( grid[i][j] == 'H') safe = false;
            for (int a = 0; a <= j; a++) {
                if (grid[0][a] == 'H') safe = false;
            }
            for (int a = 0; a <= i; a++) {
                if (grid[a][j] == 'H') safe = false;
            }
            for (int a = j; a < M; a++) {
                if (grid[i][a] == 'H') safe = false;
            }
             for (int a = i; a < M; a++) {
                if (grid[a][M-1] == 'H') safe = false;
            }
            if (safe) route++;
        }
    }
  
    for( int i = 1; i< M-1; i++) {
        for( int j = 1; j < M-1; j ++) {
              safe = true; 
            if ( grid[i][j] == 'H') safe = false;
            for (int a = 0; a <= i; a++) {
                if (grid[a][0] == 'H') safe = false;
            }
            for (int a = 0; a <= j; a++) {
                if (grid[i][a] == 'H') safe = false;
            }
            for (int a = i; a < M; a++) {
                if (grid[a][j] == 'H') safe = false;
            }
             for (int a = j; a < M-1; a++) {
                if (grid[M-1][a] == 'H') safe = false;
            }
            if (safe) route++;
        }
    }

  }
        cout<<route<<endl;
        return;
}

int main() {
    //IO("race");
    int T;
    cin>>T;
    for(int i=0;i<T;i++) {
        solve();
    }
    
}
