#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int sum_M{ A + B }, sum_m{ A + B };
	
	for (int i = 0; static_cast<int>(A / pow(10, i)); i++)
		//조건문은 A보다 높은 자리 의 수로 나누었을 때 0이됨을이용.
	{
		int i2 = pow(10, i);
		if ((A % (i2 * 10)) / i2 == 6)
			//숫자에 6이 섞인경우는 최솟값계산 때 5로 계산되므로
			//합의 최솟값에서 해당 자릿수크기로 1을 뺀다.
		{
			sum_m -= i2;
		}
		if ((A % (i2 * 10)) / i2 == 5)
			//숫자에 5가 섞인경우는 최댓값계산 때 6으로 계산되므로
			//합의 최댓값에서 해당 자릿수크기로 1을 더한다.
		{
			sum_M += i2;
		}
	}
	for (int i = 0; static_cast<int>(B / pow(10, i)); i++)
	{
		int i2 = pow(10, i);
		if ((B % (i2 * 10)) / i2 == 6)
		{
			sum_m -= i2;
		}
		if ((B % (i2 * 10)) / i2 == 5)
		{
			sum_M += i2;
		}
	}

	cout << sum_m << " " << sum_M;
}