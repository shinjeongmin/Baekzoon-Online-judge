#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int A, B, m, total{ 0 };
	//total�� A������ ���� 10�������� ��Ÿ�� ���̴�.
	cin >> A >> B >> m;
	
	for (int i = m - 1; i >= 0; i--) 
	{ // ���� �ڸ��������̴�. i�� A^i ������ ����ϹǷ� m - 1���� 0 ���� ��ȯ
		int temp;
		cin >> temp;
		total += pow(A, i) * temp;
	}

	int n{ 0 }; // A�������� mó�� B�������δ� ���� �ڸ����� �����ؾ��ϴ���.
	while (pow(B, n) < total) {
		n++;
	}n--; 
	/* B�� n�ڸ����� �������� �ٲ۰����� ū ������ �ݺ����� Ż���ϹǷ�
	n���� 1�� ������.*/

	while (total > 0 || n >=0) {
		cout << total / static_cast<int>(pow(B,n)) << " "; 
		// ���յ� �������� B�� n������ ������ B�� n�ڸ����� ������ ���ϴ� ��.
		total %= static_cast<int>(pow(B,n));
		//n������ ������ �� �� �������� ��������.
		n--;
	}
}