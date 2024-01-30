#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int count = 0;
	int z = 0;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			z = (x^y);
			if (x <= y && y <= z && z <= n) {
				if (x < y + z && y < x + z && z < x + y) {
					count++;
				}
			}
		}
	}
	cout << count;
}
