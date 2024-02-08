//http://www.usaco.org/index.php?page=viewproblem2&cpid=1109

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

/*
More concretely, for every two adjacent fence segments, one can compute the angle turned at that corner: either no turn (if the two segments are in the same direction), or a turn by 90∘
 counterclockwise (e.g. if the first segment is E and the second is N), or a turn by −90∘
 counterclockwise (e.g. if the first segment is E and the second is S). Doing a few examples by hand will reveal that the sum of these angles, over all corners of the fence, is precisely 360∘
 if the fence is counterclockwise, and −360∘
 if clockwise (other sums can be achieved if the fence is allowed to intersect itself, but we don't have to worry about this complication in this problem).
 */

void solve() {
  string s;
  cin >> s;
  int total = 0;
  int new_total = 0;
  char prev = s[0];
  for(int i=1;i<s.length();i++) {
  
    if (s[i] == s[i-1]) {
      continue;
    }
    else if (s[i-1] == 'N') {
      if (s[i] == 'E') total -= 90;
      else if ( s[i] == 'W') total += 90;
    }
    else if (s[i-1] == 'E') {
      if (s[i] == 'S') total -= 90;
      else if ( s[i] == 'N') total += 90;
    }
    else if (s[i-1] == 'S') {
      if (s[i] == 'W') total -= 90;
      else if ( s[i] == 'E') total += 90;
    }
    else if (s[i-1] == 'W') {
      if (s[i] == 'N') total -= 90;
      else if ( s[i] == 'S') total += 90;
    }
  //  log( i, s[i], total);   
  }
  if (total > 0) {
    cout << "CCW";
  }
  else {
    cout << "CW";
  }
  cout << endl;
}
int main() {
  int t;
  cin>>t;
  for(int i=0;i<t;i++) {
    solve();
  }
  
}
