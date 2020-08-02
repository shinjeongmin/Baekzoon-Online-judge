#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	int star;
	cin >> star;

	for (int i = 1; i <= star; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = star-1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << "\n";
	}
}