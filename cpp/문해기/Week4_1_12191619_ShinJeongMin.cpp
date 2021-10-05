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

		// gcd가 A또는 B보다 큰 경우 숙련도가 1보다 작아지는 경우가 발생
		if (B / gcd <= 0) {
			int big_A = (multiple + 1) * gcd;
			int res = (big_A - A) * x;

			cout << gcd << " " << res << "\n";

			continue;
		}
		else if (A / gcd <= 0) {
			multiple = B / gcd;
			int big_A = (multiple + 1) * gcd;
			int res = (big_A - B) * x;

			cout << gcd << " " << res << "\n";

			continue;
		}
		// 현재 A,B 보다 더 작은 수(두 수의 차 gcd로 나누고 나머지를 제거한 수) 중 최대공약수가 나오는 값
		int small_A = multiple * gcd;
		// 같은 최대공약수를 가진 A,B보다 더 큰 수 구하기
		int big_A = (multiple + 1) * gcd;

		int costX = (big_A - A) * x;
		int costY = (A - small_A) * y;

		int res = min(costX, costY);

		cout << gcd << " " << res << "\n";
	}
}
/*
2
7 4 4 1
9 15 3 2

2
9 100 3 4
100 9 3 4
*/