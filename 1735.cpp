#include<iostream>
using namespace std;
#define endl '\n'

// ���� ��Ŭ���� ȣ������ ����ϴ�...

// �ִ����� ���ϴ� �Լ�
int gcd(int a, int b) {
	int bigger = (a > b ? a : b), smaller = (a <= b ? a : b);
	int n = 0; // ������

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

struct fractional {
	int numerator; // ����
	int denominator; // �и�
};

fractional SumFractionalNum(fractional A, fractional B) {
	fractional result;
	//�м� �׳� ���ϱ�
	result.denominator = A.denominator * B.denominator;
	result.numerator = 
		A.numerator * B.denominator 
		+ B.numerator * A.denominator;

	int GCD = gcd(result.denominator, result.numerator);

	// �и������ �ִ������� 1�� �ƴϸ�
	if (GCD != 1)
	{
		// ���м� �����
		result.denominator /= GCD;
		result.numerator /= GCD;
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fractional A, B;
	cin >> A.numerator >> A.denominator;
	cin >> B.numerator >> B.denominator;
	fractional R = SumFractionalNum(A, B);

	cout << R.numerator << " " << R.denominator;
}