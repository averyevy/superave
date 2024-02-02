
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

bool consist(int patient_zero, int K){
    bool infected[101] = {false};
    int number_handshakes[101] = {0};
    infected[patient_zero] = true;
    for (int t=0; t<=250; t++) {
        int x = cowx[t], y = cowy[t];
        if ( x> 0) {
            if (infected[x]) number_handshakes[x]++;
            if (infected[y]) number_handshakes[y]++;
            if (number_handshakes[x] <= K && infected[x]) infected[y] = true;
            if (number_handshakes[y] <= K && infected[y]) infected[x] = true;
        }
    }
    for (int i=1; i<=N; i ++) {
        if ( infected[i] != cow_infected[i]) return false;
    }
    return true;
}
int main() {
    IO("tracing");
    int T, x, y,t;
    string s;
    cin >> N>>T>>s;
   
    for(int i=1;i<=N;i++){
        cow_infected[i] = s[i-1] == '1';
      //  log(cow_infected[i]);
    }

    for(int i=0;i<T;i++){
        cin>>t>>x>>y;
        cowx[t]=x;
        cowy[t]=y;
    }
    bool poss_i[101] = {false};
    bool poss_K[252] = {false};
    
    for(int i=1;i<=N;i++){
        for(int K=0;K<=251;K++)
            if (consist(i,K)) { 
                poss_i[i] = true;
                poss_K[K] = true;
            }
    }
    int lower_K = 251, upper_K=0, number_patient_zero=0;
    for(int K=0; K<=251;K++) if (poss_K[K]) upper_K = K;
    for(int K=251; K>=0;K--) if (poss_K[K]) lower_K = K;
    for (int i=1; i<=N; i ++) if ( poss_i[i]) number_patient_zero++;
    cout << number_patient_zero << " " << lower_K << " ";
    if ( upper_K == 251) {
        cout<< "Infinity\n";
    }
    else {
        cout<<upper_K;
    }
    return 0;
}
