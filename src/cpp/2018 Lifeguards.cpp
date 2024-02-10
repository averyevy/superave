#include <bits/stdc++.h>
using namespace std;
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
  IO("lifeguards");
  int N;
  cin>>N;
  int S[N]={0};
  int T[N]={0};
  int cov[1000]={0};
  for(int i=0;i<N;i++) {
    cin >> S[i] >> T[i];
    for (int j=S[i]; j<T[i];j++) {
      cov[j]++;
    }
  }
  

  int maxCov = 0;
  for(int i=0; i<N; i++) {
    for(int j=S[i];j<T[i];j++) {
      cov[j]--;
    }
    int curT = 0;
    for(int k=1;k<1000;k++) {
      curT = curT + min(cov[k],1);
    }
    maxCov = max(maxCov, curT);
    for(int j=S[i];j<T[i];j++) {
      cov[j]++;
    }
  }
  cout<< maxCov;
}
