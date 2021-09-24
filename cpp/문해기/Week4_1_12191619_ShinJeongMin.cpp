#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int A, B, x, y;
		cin >> A >> B >> x >> y;
		int gcd = abs(A-B); // 두수의 차 유클리드 호제법 
		// 몫 구하기
		int multiple = A / gcd;
		// 현재 A,B 보다 더 작은 수(두 수의 차 gcd로 나누고 나머지를 제거한 수) 중 최대공약수가 나오는 값
		int small_A = multiple * gcd;
		// 같은 최대공약수를 가진 A,B보다 더 큰 수 구하기
		int big_A = (multiple + 1) * gcd;

		int costX = (big_A - A) * x;
		int costY = (A - small_A) * y;

		cout << gcd << " " << min(costX, costY) << "\n";
	}
}
/*
2
7 4 4 1
9 15 3 2
*/