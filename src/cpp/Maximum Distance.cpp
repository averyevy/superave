#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	int coor[N][2];

	for (int i=0; i<N; i++) {
		cin >> coor[i][0];
	}
	for (int i=0; i<N; i++) {
		cin >> coor[i][1];
	}
	int dist = 0;
	for (int a=0; a<N; a++) {
		for (int b=0; b<N; b++) {
			int z = abs(pow((coor[a][0] - coor[b][0]), 2) + pow((coor[a][1] - coor[b][1]), 2));
			if (dist < z) {
				dist = z;
			}
		}
	}
	cout << dist << "\n";
}
