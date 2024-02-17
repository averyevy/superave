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

int Infinity = 1000000001;

struct cow {
    int x;
    int y;
    char dir;
};

void solve() {
    int n;
    cin >> n;   
    
    cow C[n];
    for(int i = 0; i < n; i ++) {

        cin >> C[i].dir >> C[i].x >> C[i].y;
    }
    vector<int> diff;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            diff.push_back(abs(C[i].x - C[j].x));

            diff.push_back(abs(C[i].y - C[j].y));
            
        }
    }
    
    sort(diff.begin(), diff.end());
    vector<int> answer(n);
    for(int i=0; i<n;i++) answer[i] = Infinity;
    for( auto &d : diff) {
        for (int i =0; i< n; i ++) {
            for (int j=0; j<n; j ++) {
                if ( C[i].dir == 'E' && C[j].dir == 'N' 
                    && C[i].x <= C[j].x 
                    && C[i].y >= C[j].y) {
                    
                    if ( C[i].x + d == C[j].x && C[j].y + min(answer[j], d) > C[i].y) {
                        answer[i] = min(d, answer[i]);
                    }
                    else if ( C[i].x + min(d, answer[i]) > C[j].x && C[j].y + d == C[i].y) {
                        answer[j] = min(d, answer[j]);
                    }
                    
                }
            }
        }
    }

    for(int i=0;i<n;i++) {
        if  (answer[i] == Infinity) {
            cout<< "Infinity"<<endl;
        }
        else {
            cout<<answer[i]<<endl;
        }
    }
}
 


int main() {
  //  IO("measurement");
   solve();
}
