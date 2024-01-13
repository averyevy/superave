#include <bits/stdc++.h>
using namespace std;

int main() {
	long n;
	cin >> n;
	long x;
	long sum = 0;
	long a = n*(1 + n)/2;
	for (long i=1; i<n; i++) {
		cin >> x;
		sum = sum + x;
		x = 0;
	}
	cout << a - sum << "\n";
}
