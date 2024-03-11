// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;


#define log(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss);  cout<< "LOG - line:" << __LINE__<< "      "; err(_it, args); cout <<endl;}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a <<"; ";
  err(++it, args...);
}

void solve(){
	int N, K;
	cin>>N>>K;
	string s; cin>>s;
	char ret[N];
	for(int i=0;i<N;i++) ret[i]='.';
	int start = -1, countG =0, countH=0, prevIdxG = -K - 1, idxG;
	int prevIdxH = -K - 1, idxH;
	for(int i=0;i<N;i++) {
    /* The G and H have to go together to achieve the optimal solution. If we place G first, then H. The solution isn't optimal.
    since the loc of H is at dis-advantage.*/
		if (s[i]=='G' && (prevIdxG + K ) < i) {
			if ( i+K >= N) {
				idxG = i;
				if (ret[idxG] == 'H') { idxG--; }
			}
			else {
				idxG = i + K;
			}
			ret[idxG]='G';
			//log(idx);
			prevIdxG = idxG;
			countG++;
		}
		if (s[i]=='H' && (prevIdxH + K ) < i) {
			if ( i+K >= N) {
				idxH = i;
				if (ret[idxH] == 'G') { idxH--; }
			}
			else {
				idxH = i + K;
			}
			ret[idxH]='H';
			//log(idx);
			prevIdxH = idxH;
			countH++;
		}
	}
	
	cout<<(countG+countH)<<endl;
	for(int i=0;i<N;i++) cout<<ret[i];
	cout<<endl;
}

int main() {
	int n;
	cin >> n;
	for(int i=0;i<n;i++) 
		solve();
}
