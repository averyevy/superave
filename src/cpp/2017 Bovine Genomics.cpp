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
  IO("cownomics");
  int N,M;
  cin>>N>>M;
  char spotty[N][M];
  char plain[N][M];
  for(int i=0;i<N;i++) {
    string s;
    cin >> s;
    for(int k=0;k<M;k++) {
      spotty[i][k]=s[k];
    }
  }
  for(int i=0;i<N;i++) {
    string s;
    cin >> s;
    for(int k=0;k<M;k++) {
      plain[i][k]=s[k];
    }
  }

  int count = 0;
  for(int k=0;k<M;k++) {
    set<char> sp={};
    set<char> pl={};
    for(int i=0;i<N;i++) {
      sp.insert(spotty[i][k]);
      pl.insert(plain[i][k]);
    }

    // Check for the absence of overlap
    bool noOverlap = true;
    for (const auto& element : sp) {
        if (pl.find(element) != pl.end()) {
            // Element is common to both sets, overlap exists
            noOverlap = false;
            break;
        }
    }
    if (noOverlap) {
      count++;
    }
  }
  cout<< count;
}
