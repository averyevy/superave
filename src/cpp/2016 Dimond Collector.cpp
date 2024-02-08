// Source: https://usaco.guide/general/io

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
  IO("diamond");
  int t,k;
  cin>>t>>k;
  int arr[t];
  for(int i=0;i<t;i++) {
    cin >> arr[i];
   // log(arr[i]);
  }
  sort(arr, arr + t);
  int selected = 0, maxsel=0;

  for(int i=0; i<t; i ++) {
    selected = 1;
    for(int j=i; j<t; j++) {
        if ( i !=j && abs(arr[j] - arr[i]) <= k) {
          selected ++;
          //log(arr[i], arr[j], selected);
        }
        maxsel = max(maxsel, selected);
    }
  }
  cout << maxsel;
  
}
