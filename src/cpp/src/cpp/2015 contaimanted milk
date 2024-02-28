//test case 9 is wrong , but the code is very simple
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;

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
    int N,M,D,S;
    cin >> N >> M >> D >>S;
	vector<pair<int, pair<int,int>>> milkdata;
	map<int,int> sickall;
    for(int i=0; i<D; i ++) {
    	int p, x, y;
    	cin>>p >> x >> y;
		milkdata.push_back(make_pair(y, make_pair(p,x)));
    }

	for(int i=0;i<S;i++) {
		int x, y;
		cin>>x >>y;
		sickall[x] = y;
	}

	set<int> pos;
	set<int> intersect;
	sort(milkdata.begin(), milkdata.end());
	for(auto &[k,v] : sickall) {
		int cow_n = k;
		int ts = v;
		set<int> badm;
		for(int i=0; i<D; i++) {
			int time = milkdata[i].first;
			pair<int, int> cow = milkdata[i].second;
			if ( time < ts && cow.first == cow_n ) {
				badm.insert(cow.second);
			//	log(cow.second);
			}
		}
		
		if (pos.size() <= 0 ) {
			pos = badm;
		}
		else {
			
			set_intersection(pos.begin(),pos.end(),
			badm.begin(),badm.end(), 
			std::inserter(intersect, intersect.begin()));
			pos = intersect;
		}
	}
	set<int> sickcows;
	for( auto &c : pos ) {
		for(int i=0; i<D; i++) {
			int time = milkdata[i].first;
			pair<int, int> cow = milkdata[i].second;
			if ( cow.second == c ) {
				sickcows.insert(cow.first);
			}
		}
	}
	cout<<sickcows.size()<<endl;
	
}


int main() {
	IO("badmilk");
	solve();
}
