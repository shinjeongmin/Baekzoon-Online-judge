#include<iostream>
using namespace std;
#define endl '\n'

// 역시 유클리드 호제법은 대단하다...

// 최대공약수 구하는 함수
int gcd(int a, int b) {
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

struct fractional {
	int numerator; // 분자
	int denominator; // 분모
};

fractional SumFractionalNum(fractional A, fractional B) {
	fractional result;
	//분수 그냥 더하기
	result.denominator = A.denominator * B.denominator;
	result.numerator = 
		A.numerator * B.denominator 
		+ B.numerator * A.denominator;

	int GCD = gcd(result.denominator, result.numerator);

	// 분모분자의 최대공약수가 1이 아니면
	if (GCD != 1)
	{
		// 기약분수 만들기
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