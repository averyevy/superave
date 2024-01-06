/*
ID: avelynj1
TASK: test
LANG: C++                 
*/

#define IO(NAME) \
    cin.tie(0)->sync_with_stdio(0); \
    if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
    freopen(NAME ".out","w",stdout); 

#include <bits/stdc++.h>
using namespace std;

int main() {
    	IO("cowsignal");
	int height, width;
	int scale;
	cin >> height >> width >> scale;

	vector<string> signal(height);
	for (string &r : signal) { cin >> r; }

	for (int i = 0; i < scale * height; i++) {
		for (int j = 0; j < scale * width; j++) {
			cout << signal[i / scale][j / scale];
		}
		cout << '\n';
	}
}

