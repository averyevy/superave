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

double PI = 4*atan(1);
//INT_MAX, INT_MIN

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




void solve(){
    int N;
    cin >> N;
    vector<vector<char>> grid(N, vector<char>(N));
  //the way to init 2d array
    vector<vector<char>> ans(N, vector<char>(N,'.'));
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>grid[i][j];
        }    
    }
 
    int K;
    cin>>K;
  //we need to declare the vector after getting K value.
    vector<vector<char>> stamp(K, vector<char>(K));
    for(int i=0;i<K;i++) {
        for(int j=0;j<K;j++) {
            cin>>stamp[i][j];
        }    
    }
  //the boundary is [0 , N-K]
        for(int i=0; i<=N-K;i++){
            for(int j=0; j<=N-K;j++){
                for(int r=0; r<4;r++){
                bool valid = true;
                for(int s=0;s<K  ;s++) {
                    for(int t=0;t<K  ;t++) {
                        if (grid[i+s][j+t] != '*' && stamp[s][t] == '*') {
                            valid = false;
                            break;
                        }
                    }   
                }
                
                if (valid) {
                    //log(i,j);
                    for(int s=0;s<K;s++) {
                        for(int t=0;t<K;t++) {
                            if ( stamp[s][t] =='*')
                                 ans[i+s][j+t] = stamp[s][t];
                        }   
                    }
                }

                //rotate 90 degree clock wise
                vector<vector<char>> newStamp(K, vector<char>(K));
                for(int a=0; a<K; a++ ) {
                    for(int b=0; b<K;b++) {
                        newStamp[a][b] = stamp[K-b-1][a];
                    }   
                }
                stamp = newStamp;
            }
        }
    }

    bool found = true;
    for(int a=0;a<N;a++) {
        for(int b=0;b<N;b++) {
            if (grid[a][b] != ans[a][b]) {
                found = false;
                break;
            }
        }
    }

    cout<< (found ? "YES" : "NO") <<endl;
 }

int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
        solve();
}
