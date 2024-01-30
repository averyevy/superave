#include <bits/stdc++.h>
using namespace std;

int main() {
	unsigned long long a;
	unsigned long long b;
	cin >> a >> b;
	unsigned long long x = 1;
	unsigned long long y = 1;
	if (b-a > 5) {
		cout << 0;
	}
	else {
		for (unsigned long long i = a+1; i <= b; i++) {
			x = x*(i%10);
		}
	cout << x%10;
	}
}
