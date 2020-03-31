#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	int basket[100];

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		basket[i] = i + 1;
	}

	// reverse�Լ� ���
	// ���� : first ���� last �� ������ ���ҵ��� ������ �������� �����´�.
	for (int k = 0; k < M; k++) {
		int i, j;
		cin >> i >> j;
		reverse(&basket[i - 1], &basket[j - 1] + 1);
	}

	for (int i = 0; i < N; i++) {
		cout << basket[i] << " ";
	}
}