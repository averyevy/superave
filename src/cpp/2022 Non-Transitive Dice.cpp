http://usaco.org/index.php?page=viewproblem2&cpid=1180
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

using Die = array<int, 4>;

bool beat(const Die& A, const Die& B ) {
    int win = 0;
    int loss = 0;
    for (int i=0;i<4;i++) 
    for (int j = 0;j<4;j++) {
        if (A[i] > B[j]) win++;
        if (A[i] < B[j]) loss++;
    }
    return win > loss;
}

bool non_transition(const Die& A, const Die& B) {
    for(int a = 1; a <= 10; a++) 
    for(int b = 1; b <= 10; b++) 
    for(int c = 1; c <= 10; c++) 
    for(int d = 1; d <= 10; d++) {
        Die C{a,b,c,d};
        if (beat(A,B) && beat(B,C) && beat(C,A)) return 1;
        if (beat(B,A) && beat(C,B) && beat(A,C)) return 1;
    }
    return 0;
}

int main() {
    //IO("hps");
    int N;
    cin>>N;
    array<string,4> blocks;
    for(int i=0;i<N;i++) {
        Die A,B;
        for(int j=0;j<4;j++) cin>>A[j];
        for(int j=0;j<4;j++) cin>>B[j];
        if(non_transition(A,B)) {
            cout<<"yes";
        }
        else {
            cout<< "no";
        }
        cout<<endl;
    }
    
    return 0;
}
