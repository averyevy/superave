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

void solve() {
  int t;
  cin>>t;
  int arr[t];
  int sum = 0;
  for(int i=0;i<t;i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  int target_sum, op = 0;
  int cur_sum = 0;

  for(int i=t;i>0;i--) {
    //check if we can separate into i range.
    if ( sum % i !=0 ) continue;
    target_sum = sum/i;
    bool ok = false;
    cur_sum = 0;
    for(int j=0;j<t;j++) {
        cur_sum += arr[j];
      if ( cur_sum == target_sum ) {
        ok = true;
        cur_sum = 0;
      }
      else if (cur_sum > target_sum) {
        ok = false;
        break;
      }
    }
    if (ok) {
      //The key point of number of options is n - number of ranges. since 
      // the rest of elements need to combine into a range.
      cout<<t - i<<endl;
      break;
    }
  }
}
int main() {
  // IO("balancing");
  int N;
  cin >> N;
  forn(i,N) {
    solve();
  }
}
