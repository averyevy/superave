
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
	IO("triangles");
	int N;
	cin >> N;
	int X[N];
	int Y[N];
	for( int i=0;i<N;i++) {
		cin>>X[i]>>Y[i];
	}
	int area = 0;
	int maxArea = 0;
	for( int i=0;i<N;i++) {
		for( int j=0;j<N;j++) {
			for( int k=0;k<N;k++) {
				if (X[i] == X[j] && Y[j] == Y[k]) {
					area = abs( Y[i] - Y[j] ) * abs( X[j] - X[k] );
				}
				maxArea = max(maxArea, area);
			}
		}
	}
	cout << maxArea;
}
