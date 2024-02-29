

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
int getExplosionIndex(vector<int> a, int startIndex, bool goLeft) {
	int lastExpIndex = startIndex;
	int r = 1;
	while(lastExpIndex > 0 && lastExpIndex < a.size() - 1) {
		int direction = 0;
		if (goLeft) {
			direction = -1;
		}
		else {
			direction = 1;
		}
		int nextIndex = lastExpIndex;
		while(nextIndex + direction >= 0 && nextIndex + direction < a.size()
		&& abs(a[nextIndex+direction] - a[lastExpIndex]) <= r) {
			nextIndex += direction;
		}
		if (nextIndex == lastExpIndex) break;
		lastExpIndex = nextIndex;
		r++;
	}
	return lastExpIndex;
}



void solve() {
	ll n;
	cin >> n;
	vector<int> a(n);
	set<int> index;
	for(int i=0; i<n;i++) { 
		cin>>a[i];
		index.insert(a[i]);
	}
	sort(a.begin(),a.end());
	//for(int i=0; i<n; i++) {cout<<a[i]<<" ";}
	// if (n<=1) {
	// 	cout<<n<<endl;
	// 	return;
	// }
	int range = 0, cnt = 1;
	for(int i=0; i<n; i++) {
		int left = getExplosionIndex(a, i, true);
		int right = getExplosionIndex(a, i, false);
		cnt = right - left + 1;
		//log(i,a[i], leftcnt, rightcnt, cnt);
		range = max(range, cnt);
	}
	cout<<range<<endl;
}

int main() {
	IO("angry");
	
	solve();
	// int n;
	// cin >> n;
	// for(int i=0; i<n;i++) {
	// 	solve();
	// }
		
}
