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
		int gcd = abs(A-B); // �μ��� �� ��Ŭ���� ȣ���� 
		// �� ���ϱ�
		int multiple = A / gcd;
		// ���� A,B ���� �� ���� ��(�� ���� �� gcd�� ������ �������� ������ ��) �� �ִ������� ������ ��
		int small_A = multiple * gcd;
		// ���� �ִ������� ���� A,B���� �� ū �� ���ϱ�
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