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
  IO("balancing");
  int N, B;
  cin >> N >> B;
  int X[N];
  int Y[N];

  for(int i=0;i<N;i++) {
    cin >> X[i] >> Y[i];
  }

  int minM = MOD, maxM = 0, minLB = MOD, ret = 0;
  for(int x = 0; x < N; x ++)
    for(int y = 0; y < N; y ++) {
      int a = X[x] + 1;
      int b = Y[y] + 1;
      int reg1=0, reg2=0, reg3=0, reg4=0;

      for( int i = 0; i < N; i ++) {
        if (X[i] < a && Y[i] < b) reg1++;
        else if (X[i] > a && Y[i] < b) reg2++;
        else if (X[i] > a && Y[i] > b) reg3++;
        else if (X[i] < a && Y[i] > b) reg4++;
      }
      
      maxM = max(reg1, max(reg2, max(reg3, reg4)));
      
       if ( minLB > maxM ) {
        minLB = maxM; 
        ret = maxM;
      }

    }
    
  cout<< ret;
}
