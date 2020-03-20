#include <iostream>
#include <vector>
using namespace std;
vector<bool> isPrimeVec;
void eratos(int n);
int numOfPrime(int min, int max);

int main() {
	int n{1};

	cin >> n; //ù��° �� �Է�
	while (n != 0) // n�� 0�� �ԷµǸ� �ݺ��� Ż��.
	{
		eratos(2 * n); // 2n��ŭ ũ�⸦ �Ҵ��� �����佺�׳׽��� ü ����.
		cout << numOfPrime(n + 1, 2 * n) << "\n"; // n���� ũ��, 2n������ �Ҽ��� ���� ���.

		cin >> n;
	}
}

// �ּ�, �ִ밪�� ������ �� ������ �Ҽ����� ������ ��ȯ�ϴ� �Լ�.
int numOfPrime(int min, int max) {
	int numofprime{ 0 };

	for (int i = min; i <= max; i++) {
		numofprime += isPrimeVec[i];
	}

	return numofprime;
}

void eratos(int n) {
	isPrimeVec.assign(n + 1, true); //���Ϳ� true�� �Ҵ�
	//isPrimeVec[0] = isPrimeVec[1] = isPrimeVec[2] = true; //0,1,2���� true�Ҵ� (�Ҽ��� �ƴ�����)
	
	for (int i = 2; i <= static_cast<int>(n / 2); i++) 
	{
		if (isPrimeVec[i] == true) 
		{ 
			// �Ҽ��� ����
			for (int j = 2; i * j <= n; j++) 
			{
				// n������ i�� ������� ����
				isPrimeVec[i * j] = false;
			}
		}
	}
}