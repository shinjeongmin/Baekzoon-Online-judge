#include<iostream>
using namespace std;
#define endl '\n'

// 최대공약수 구하는 함수
int gcd(int a,int b) {
	int bigger = (a > b ? a : b), smaller = (a <= b ? a : b);
	int n = 0; // 나머지
	
	while (1) {
		n = bigger % smaller;
		if (n == 0)
			return smaller;
		else {
			bigger = smaller;
			smaller = n;
		}
	}
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int a,b;
	cin >> a >> b;
	cout << gcd(a,b) << endl << lcm(a,b);
}