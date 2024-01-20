/*
ID: avelynj1
TASK: test
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;

#define IO(NAME) \
    cin.tie(0)->sync_with_stdio(0); \
    if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
    freopen(NAME ".out","w",stdout); 

int main() {
	IO("triangles");
	int N;
	cin >> N;
	int coord[N][2];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> coord[i][j];
		}
	}
	int area = 0;
	int side1 = 0, side2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (coord[i][0] == coord[j][0] && coord[j][1] == coord[k][1]) {
					side1 = abs(coord[i][1] - coord[j][1]);
					side2 = abs(coord[j][0] - coord[k][0]);
					area = max(area, side1*side2);
				}
			}
		}
	}
	cout << area;
}
