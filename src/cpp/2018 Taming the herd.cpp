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

void printarr(int a[], int N) {
	for ( int i = 0; i < N; i ++) {
		cout<<a[i]<<",";
	}
	cout<<endl;
}

#define a_macro(args...) sum(args)
int sum() { return 0; }
template<typename T, typename... Args>
auto sum(T a, Args... args) { return a + sum(args...); }

int main() {
	IO("taming");
	int N;
	cin >> N;
	int arr[N];

	for ( int i = 0; i < N; i ++ ) {
		cin >> arr[i];

	}
	int count = 1, pos = 0;
	int t = -1;
	for ( int i = N - 1; i > 0; i -- ) {

		if ( arr[i] != -1 && t != -1 && arr[i] != t ) {
			cout<< -1<< endl;
			return 0;
		}
		if (arr[i] != -1) {
			t = arr[i];
		}
		if ( arr[i] == -1 )	{
			arr[i] = t;
		}
		if ( arr[i] == 0 ) {
			count++;
		}
		if(arr[i] == -1)
			pos++;
		if(t!= -1) {
			t--;
		}
	}
	
	cout <<count<<" "<<count+pos<<endl;
	
}
