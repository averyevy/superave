
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
    IO("mowing");
    int N;
    cin >> N;
   
    int P[2000][2000];
    forn(i,2000)
    forn(j,2000)
    P[i][j]=-1;
    bool f = false;
    // P[5000][5000] = -1;
    int x = 1000, y=1000;
    int t = 0;
    int minx = 1000;
    forn(i,N){ 
        int u; char d;
        cin >> d >> u;
        for(int j=0;j<u;j++) {
            if (d=='N'){ 
                y++;
            }
            else if (d=='S'){ 
                y--;
            }
            else if (d=='E'){ 
                x++;
            }
            else if (d=='W'){ 
                x--;
            }
            t++;
            if ( P[x][y] != -1 ) {
                minx = min( minx, t-P[x][y]);
                f=true;
                //log(x,y,minx);
            }
            P[x][y] = t;
            //log(x, y, P[x][y]);
        }
    };
    if (f) cout <<  minx;
    else cout << -1;
    return 0;
}
