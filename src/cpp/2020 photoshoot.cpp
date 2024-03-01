

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



void solve() {
	int n;
	cin >> n;
	vector<int> B(n,0);
	vector<int> A(n);
	set<int> C;
	bool ok = true;
	for(int i=1;i<n;i++) cin>>B[i];
	for(int i=1;i<=n;i++) {
		A[0] = i;
		C.insert(A[0]);
		ok = true;
		for( int j=1; j<n;j++) {
			A[j] = B[j]-A[j-1];
			if ((C.count(A[j]) == 0) && A[j] > 0 && A[j] <= n) {
				C.insert(A[j]);
			} else {
				ok = false;
				break;
			}
		}
		if (ok && C.size() == n) {
			for(int k=0;k<n;k++) {
				cout<<A[k];
				if(k<n-1) cout << ' ';
			}
			cout<<endl;
			break;
		}
		C.clear();
	}
	
}

int main() {
	IO("photo");
	
	solve();
	// int n;
	// cin >> n;
	// for(int i=0; i<n;i++) {
	// 	solve();
	// }
		
}
