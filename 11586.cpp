#include <iostream>
#include <algorithm>
using namespace std;

char befarr[100][100], curarr[100][100], zeroarr[100][100];
int N, K;
void inputarr(), printarr(), reverseRL(), reverseUD();

int main() {
	cin >> N;

	inputarr();

	cin >> K;
	switch (K) {
	case 1:
		printarr();
		break;
	case 2:
		reverseRL();
		printarr();
		break;
	case 3:
		reverseUD();
		printarr();
		break;
	}
}

void inputarr() {
	// ���������� ��� �Է�.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> curarr[i][j];
		}
	}
}

void printarr() {
	// ��ü ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << curarr[i][j];
		}
		cout << "\n";
	}
}

void reverseRL() {
	// curarr -> befarr �� ���� �� curarr�ʱ�ȭ
	copy(&curarr[0][0], &curarr[0][0] + (100 * 100), &befarr[0][0]);
	copy(&zeroarr[0][0], &zeroarr[0][0] + (100 * 100), &curarr[0][0]);

	// �¿����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			curarr[i][(N - 1) - j] = befarr[i][j];
		}
	}
}

void reverseUD() {
	// curarr -> befarr �� ���� �� curarr�ʱ�ȭ
	copy(&curarr[0][0], &curarr[0][0] + (100 * 100), &befarr[0][0]);
	copy(&zeroarr[0][0], &zeroarr[0][0] + (100 * 100), &curarr[0][0]);

	// ���Ϲ���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			curarr[(N - 1) - i][j] = befarr[i][j];
		}
	}
}