#include <bits/stdc++.h>
using namespace std;

#define IO(NAME) \
    cin.tie(0)->sync_with_stdio(0); \
    if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
    freopen(NAME ".out","w",stdout); 

int main() {
	IO("cownomics");
	int N;
	int M;
	cin >> N >> M;
	char spotty[N][M];
	char plain[N][M];
	for (int i = 0; i < N; i++) {
		string feature;
		cin >> feature;
		for (int j = 0; j < M; j++) {
			spotty[i][j] = feature[j];
		}
	}
	for (int i = 0; i < N; i++) {
		string feature;
		cin >> feature;
		for (int j = 0; j < M; j++) {
			plain[i][j] = feature[j];
		}
	}
	int count = 0;
	for (int i = 0; i < M; i++) {
		set<char> seen;
		for (int j = 0; j < N; j++) {
			seen.insert(spotty[j][i]);
		}
		bool good = true;
		for (int x = 0; x < N; x++) {
			char cur = plain[x][i];
			//check in seen 
			if (seen.count(cur) > 0) {
				good = false;
				break;
			}
		}
		if (good) {
			count++;
		}
	}
	cout << count;
}
