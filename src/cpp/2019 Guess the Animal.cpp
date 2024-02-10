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
  IO("guess");
  int N;
  cin >> N;
 
  vector<vector<string>> animals(N);

  for(int i=0;i<N;i++) {
    string animal;
    cin >> animal;
    int t;
    cin >> t;
    forn(j,t) {
      string a;
      cin >> a;
      animals[i].push_back(a);
    
      }
  }


  int maxC = 0;

  for(int i=0;i<N;i++) {
    for( int j=i+1; j<N; j++) {
     int common = 0;
      for( auto &featurei: animals[i]) {
        for( auto &featurej: animals[j]) {
          if (featurei == featurej) {
            common++;
            //log(i, j, featurei, common);
            break;
          }
        }
      }
      maxC = max( maxC, common);
      
    }
    
  }
  cout<< maxC+1;
}
