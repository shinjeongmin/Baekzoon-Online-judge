#include<iostream>
using namespace std;

void charactor(int n);

int main() {
	int N;

	cin >> N;

	int MaxN = N + N - 1; // �������ٿ��� ����� *�� ���� ��.
	for (int i = 1; i <= N; i++){ // ���� ������ �ݺ���

		int odd_of_line = i * 2 - 1; //�� �ٿ��� *�� �������� ������ ���Ե� �κ��� ���� �� ����.

		for (int j = 0; j < (MaxN - (odd_of_line)) / 2; j++) { // *�� �ѷ����� �κ��� ������ �� ������ ����
			cout << " ";
		}
		charactor(odd_of_line);
		cout << endl;
	}
}

void charactor(int n) { // *�� �ѷ��ΰ� * ������ĭ���� �̷���� �κ�. (* * *)
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
			cout << " ";
		else
			cout << "*";
	}
	return;
}