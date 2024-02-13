// Source: https://usaco.guide/general/io

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

#define log(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss);  cout<< "LOG - line:" << __LINE__<< "      "; err(_it, args); cout <<endl;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a <<"; ";
	err(++it, args...);
}

int main() {
  IO("blist");
  int N;
  cin >> N;
  
  int start[1001] = {};
  int finish[1001] = {}; 
  int buckets[N]= {};

  for(int i=1; i<=N; i ++) {
    int s, t, b;
    cin >> s >> t >>b;
    start[s] = i;
    finish[t] = i;
    buckets[i] = b;
  }
  int maxbuckets = 0;
  int curbuckets = 0;

  for(int i=1; i<=1000; i ++) {
      if ( start[i] > 0 ) {
        curbuckets += buckets[start[i]];
      }
      maxbuckets = max( maxbuckets, curbuckets);
      if ( finish[i] > 0 ) {
        curbuckets -= buckets[finish[i]];
      }
  }
  
   cout << maxbuckets;
}
