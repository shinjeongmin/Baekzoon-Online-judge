#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int sum_M{ A + B }, sum_m{ A + B };
	
	for (int i = 0; static_cast<int>(A / pow(10, i)); i++)
		//���ǹ��� A���� ���� �ڸ� �� ���� �������� �� 0�̵����̿�.
	{
		int i2 = pow(10, i);
		if ((A % (i2 * 10)) / i2 == 6)
			//���ڿ� 6�� ���ΰ��� �ּڰ���� �� 5�� ���ǹǷ�
			//���� �ּڰ����� �ش� �ڸ���ũ��� 1�� ����.
		{
			sum_m -= i2;
		}
		if ((A % (i2 * 10)) / i2 == 5)
			//���ڿ� 5�� ���ΰ��� �ִ񰪰�� �� 6���� ���ǹǷ�
			//���� �ִ񰪿��� �ش� �ڸ���ũ��� 1�� ���Ѵ�.
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