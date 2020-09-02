#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	int N, sum{ 0 };
	cin >> N;
	for (int i = 0; i < N; i++) {
		int multiTap;
		cin >> multiTap;
		sum += multiTap;
	}
	sum -= N-1;
	cout << sum;
}

// 제한시간 9:30