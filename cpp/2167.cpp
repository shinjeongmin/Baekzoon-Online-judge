#include <iostream>
using namespace std;

int main() {
	int N, M, K, i, j, x, y;
	int result{ 0 };

	cin >> N >> M;

	int arr[300][300] = {}; // �迭

	for (int i = 0; i < N; i++){ //�ش� �ε����� �����ϴ� �迭�� ���� �ֱ�
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			arr[i][j] = temp;
		}
	}

	cin >> K; // ���� ���� �κ��� ����

	for (int k = 0; k < K; k++) {
		cin >> i >> j >> x >> y; //�� ��ǥ �Է�

		result = 0; //�� �ʱ�ȭ

		for (int i2 = i; i2 <= x; i2++) {
			for (int j2 = j; j2 <= y; j2++) {
				result += arr[i2 - 1][j2 - 1]; //�迭�� (0,0)���� �����̹Ƿ� 1�� �� ��ǥ���� ���.
			}
		}
		cout << result <<  "\n";
	}
}