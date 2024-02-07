
//http://usaco.org/index.php?page=viewproblem2&cpid=615

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

#define IO(NAME) \
    cin.tie(0)->sync_with_stdio(0); \
    if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
    freopen(NAME ".out","w",stdout); 


int main() {
  IO("pails");

  int X,Y,M;
  cin >> X>>Y>>M;
  int cur = 0, maxcur = 0;
  //important to use i<=M/X
  for (int i=0;i<=M/X;i++) {
    for (int j=0;j<=M/Y;j++) {
      cur = i*X + j*Y;
      if ( cur <= M ) {
        maxcur = max(cur, maxcur);
      }

    }
  }
  cout<< maxcur << endl;
}
