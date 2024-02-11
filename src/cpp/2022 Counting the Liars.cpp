#include <stdio.h>
#include <stdint.h>
 
#include <vector>
#include <algorithm>
using namespace std;
 
 int main() {

	int N;
	cin >> N;
	vector<pair<int,char>> loc;

	for( int i=0;i<N;i++) {
		char c; 
		int t;
		cin >> c >> t;
		loc.push_back(make_pair(t,c));
	}

	int minLiars = N;
	sort(loc.begin(), loc.end());

	for( int i = 0; i < N; i ++) {
		int curLiars = 0;
		for ( int j = 0 ; j < i; j++) {
			if (loc[j].second == 'L') 
			curLiars++;
		}
		for ( int j = i+1 ; j < N; j++) {
			if (loc[j].second == 'G') 
			curLiars++;
		}
		minLiars = min(minLiars, curLiars);
	}
	cout << minLiars;
}
