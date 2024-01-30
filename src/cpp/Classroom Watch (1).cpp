#include <bits/stdc++.h>
using namespace std;

int main() {
	long n;
	cin >> n;
	long x = 0;
	long sum = 0;
	long count = 0;
	vector<long> ns = {};
	for (long i = n - 81; i < n; i++) {	
		x = i;
		sum = i;
		while (x > 0) {
			sum = sum + x%10;
			x = x / 10;
		}
		if (sum == n) {
			count++;
			ns.push_back(i);
		}
	}
	cout << count << "\n";
	for (auto i : ns) {
		cout << i << "\n";
	}

}
