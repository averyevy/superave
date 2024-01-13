#include <bits/stdc++.h>
using namespace std;

int main() {
	string input;
	cin >> input;
	int rep = 1;
	int next;
	int n = input.length();
	int i = 0;
	int largest;
	while (i < n) {
		char x = input[i];
		next = i + 1;
		rep = 1;
		while (input[next] == x) {
			rep++;
			next++;
		}
		if (rep > largest) {
			largest = rep;
		}
		
		i = next;
	}
	cout << largest;
	
	
}