#include<iostream>
using namespace std;

int honeyMoon(int N) {
	if (N == 1)
		return 1;
	else {
		for (int i = 2; ; i++) {
			int sum = 1;
			for (int j = 1; j < i; j++) {
				if (N <= sum) {
					return i - 1;
				}
				sum += 6 * j;
			}
		}
	}
}

int main() {
	int N; 
	cin >> N;
	cout << honeyMoon(N);
}