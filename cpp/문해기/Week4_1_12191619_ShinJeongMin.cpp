#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, A, B, x, y, g, answer;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> A >> B >> x >> y;
		g = abs(A - B);

		// g�� A�Ǵ� B���� ū ��� ���õ��� 1���� �۾����� ���
		if (B / g <= 0 || A / g <= 0) {
			answer = (g - (A % g)) * x;
			cout << g << " " << answer << "\n";

			continue;
		}

		// g�� ���� �������� �����Ƿ� A�� B�� �������(�� if���� ��������)
		answer = min((A % g) * y, (g - (A % g)) * x);

		cout << g << " " << answer << "\n";
	}
}

//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int T;
//	cin >> T;
//	for (int t = 0; t < T; t++) {
//		int A, B, x, y;
//		cin >> A >> B >> x >> y;
//		int gcd = abs(A-B); // �μ��� �� ��Ŭ���� ȣ���� 
//		// �� ���ϱ�
//		int multiple = A / gcd;
//
//		// gcd�� A�Ǵ� B���� ū ��� ���õ��� 1���� �۾����� ��찡 �߻�
//		if (B / gcd <= 0) {
//			int big_A = (multiple + 1) * gcd;
//			int res = (big_A - A) * x;
//
//			cout << gcd << " " << res << "\n";
//
//			continue;
//		}
//		else if (A / gcd <= 0) {
//			multiple = B / gcd;
//			int big_A = (multiple + 1) * gcd;
//			int res = (big_A - B) * x;
//
//			cout << gcd << " " << res << "\n";
//
//			continue;
//		}
//		// ���� A,B ���� �� ���� ��(�� ���� �� gcd�� ������ �������� ������ ��) �� �ִ������� ������ ��
//		int small_A = multiple * gcd;
//		// ���� �ִ������� ���� A,B���� �� ū �� ���ϱ�
//		int big_A = (multiple + 1) * gcd;
//
//		int costX = (big_A - A) * x;
//		int costY = (A - small_A) * y;
//
//		int res = min(costX, costY);
//
//		cout << gcd << " " << res << "\n";
//	}
//}

/*
2
7 4 4 1
9 15 3 2

output
3 1
6 6

2
9 100 3 4
100 9 3 4

output 
91 246
91 246
*/