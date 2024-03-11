//http://usaco.org/index.php?page=viewproblem2&cpid=1253


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

int INF = 1000000001;


void solve() {
    int n,m;
    cin>>n>>m;
    vector<string> inputs(m);
    vector<char> outputs(m);

    vector<bool> tcPassed(m,false);
    for(int i=0;i<m;i++) {
        cin>>inputs[i] >>outputs[i];
    }

    while(true) {
        bool foundIfStatement = false;
	    /* focus on the iteration of the run. Everytime it tried to mark the 
             if (inputs[bit]) then return val
             
	    */
        for(int bit = 0; bit < n; bit ++) {
            if (foundIfStatement) break;
            for (int val = 0; val<= 1; val++) {
                if (foundIfStatement) break;
                for (int output = 0; output <=1; output++) {
                    if (foundIfStatement) break;
                    bool consistent = true;
                    bool atLeastOneinput = false;
	             /* check all the inputs consist with this inputs combination 0->1,  1->1 */		
                    for(int tc = 0; tc < m; tc++) {
                        if ( tcPassed[tc] ) continue;
                        if (inputs[tc][bit] == '0' + val) {
                            atLeastOneinput = true;
                            if (outputs[tc] != '0' + output) {
                                consistent = false;
                            }
                        }
                    }

                    if (consistent && atLeastOneinput) {
                        foundIfStatement = true;
                        for(int tc=0; tc<m; tc++) {
                            if ( tcPassed[tc]) continue;
                            if (inputs[tc][bit] == '0' + val)
                                tcPassed[tc] = true;
                        }
                    }
                }

            }
        }
        if ( !foundIfStatement) break;
    }

    bool ok = true;
    for (int i=0; i<m;i++) {
        if (tcPassed[i] == false) {
            ok = false;
        }
    }
   if (ok) {
		cout << "OK" << endl;
	} else {
		cout << "LIE" << endl;
	}
}

int main() {
    //IO("race");
    int T;
    cin>>T;
    for(int i=0;i<T;i++) {
        solve();
    }
    
}
