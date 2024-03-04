

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

ll div_up(ll x, ll y)
{
    return  x/y + (x % y != 0);
}

void reverse_inplace(int a[], int s, int t) {
	while( s<t) {swap(a[s],a[t]); s++; t--;}
}

void solve() {
	int N;
	cin >> N;
	vector<pair<int,int>> cows(N);
	vector<int> sick;
	for(int i=0;i<N;i++) {
		int m,n;
		cin>>m>>n;
		cows[i] = make_pair(m,n);
		if ( n == 1 ) sick.push_back(m);
	}
	sort(cows.begin(), cows.end());
	int last0 = -1, last1 =-1, smallest_gap = 1000000, gap_start = -1;
	for(int i=0;i<N;i++) {
		auto p = cows[i];
		if (p.second == 0 ) {
			last0 = p.first;
			if (last1 != -1) {
				int d = p.first - last1;
				if ( d < smallest_gap ) smallest_gap = d;	
			}
		 }
		if ( p.second == 1 ) {
		 	last1 = p.first;
			if (last0!= -1) {
				int d = p.first - last0;
				if ( d < smallest_gap ) smallest_gap = d;
			}
		}
	}

	sort(sick.begin(), sick.end());
	int count = 1;
	for(int i=1; i<sick.size(); i ++) {
		if (sick[i] - sick[i-1] >= smallest_gap) { 
			count++;
		}
	}
	cout<<count;
}

int main() {
	IO("socdist2");
	solve();

	// for(int i=0; i<k;i++) {
	// 	solve();
	// }
		
}
