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

void solve() {
    int n;
    cin >> n;
    vector<pair<int,pair<string, int>>> data;
    map<string, int> arr;
    for(int i=0; i<n; i ++) {
        int d,t; string c;
        cin>>d >> c >> t;
        data.push_back(make_pair(d, make_pair(c,t)));
        arr[c] = 7;
    }
    sort(data.begin(), data.end());

    int rank1 = 7;
    string cur = "";
    set<string> display = {};
    int count = 0;
    for(auto &cur_data : data ) {
        pair<string, int> curdata = cur_data.second;
        string cow = curdata.first;
        arr[cow] += curdata.second;

        int maxMilk = 0;
        for (auto const& [key, val] : arr) {
            maxMilk = max(val, maxMilk);
        }
        set<string> new_display = {};
        for (auto const& [key, val] : arr) {
            if ( val == maxMilk ) {
                new_display.insert(key);
            }
        }
        if (display != new_display) {
            count++;
            display = new_display;
        }
    }
    cout << count << endl;

}
 


int main() {
    IO("measurement");
   solve();
}
