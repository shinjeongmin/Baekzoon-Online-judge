#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N{ 0 }, sum{ 0 };
		cin >> N;
		for(int n = 0;n < N;n++){
			int i;
			cin >> i;
			sum += i;
		}
		cout << sum << endl;
	}
}