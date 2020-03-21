#include <iostream>
#include <algorithm>
using namespace std;
int befArr[100][100]; // �迭�� ���� �� ������ �迭�� ����
int curArr[100][100]; // �迭�� ���� �� ������ �迭�� ����
int groupNum[100][100]; // 5,6������ 4���� �κ����� ���� �� �׷��ȣ�� ��� �迭
int N, M, R;

void inputArr(), printArr(), copyArr(), grouping();
void rotateArr1(), rotateArr2(), rotateArr3(), rotateArr4(), rotateArr5(), rotateArr6();

int main() {
	int kindOfRotate;
	cin >> N >> M >> R;
	inputArr();

	for (int i = 0; i < R; i++) {
		cin >> kindOfRotate;
		switch (kindOfRotate) {
		case 1:
			rotateArr1();
			break;
		case 2:
			rotateArr2();
			break;
		case 3:
			rotateArr3();
			break;
		case 4:
			rotateArr4();
			break;
		case 5:
			rotateArr5();
			break;
		case 6:
			rotateArr6();
			break;
		}
	}
	printArr();
}

void inputArr() {
	// �迭 �Է��Լ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> curArr[i][j];
		}
	}

}

void printArr() {
	// �迭 ����Լ�
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if(curArr[i][j])
				cout << curArr[i][j] << " ";
		}
		if(curArr[i][0])
			cout << "\n";
	}
}

void copyArr() { 
	//befArr 0���� �ʱ�ȭ
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			befArr[i][j] = 0;
		}
	}

	// cur�迭�� ���� before �迭�� ����.
	copy(&curArr[0][0], &curArr[0][0] + (100 * 100), &befArr[0][0]);
	
	//curArr 0���� �ʱ�ȭ
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			curArr[i][j] = 0;
		}
	}
}

void grouping() {
	//0���� �ʱ�ȭ
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			groupNum[i][j] = 0;
		}
	}

	// �׷��ȣ�� �׷��ȣ�迭�� �ֱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i < N / 2){
				// 1,2 �׷�
				if (j < M / 2) // 1 �׷�
					groupNum[i][j] = 1;
				else // 2 �׷�
					groupNum[i][j] = 2;
			}
			else {
				// 3,4 �׷�
				if (j < M / 2) // 4 �׷�
					groupNum[i][j] = 4;
				else // 3 �׷�
					groupNum[i][j] = 3;
			}
		}
	}
}

void rotateArr1() {
	// �迭 ������ 1��
	copyArr(); // ����迭�� bef�迭�� ����

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			curArr[(N - 1) - i][j] = befArr[i][j];
		}
	}
}

void rotateArr2() {
	// �迭 ������ 2��
	copyArr(); // ����迭�� bef�迭�� ����

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			curArr[i][(M - 1) - j] = befArr[i][j];
		}
	}
}

void rotateArr3() {
	// �迭 ������ 3��
	copyArr(); // ����迭�� bef�迭�� ����

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			curArr[j][(N - 1) - i] = befArr[i][j];
		}
	}

	// -- ���� -- �Ѻ� 90�� ȸ���� N�� M�� ���� �ٲ��� ��.
	int temp{ N };
	N = M;
	M = temp;
}

void rotateArr4() {
	// �迭 ������ 4��
	copyArr(); // ����迭�� bef�迭�� ����

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			curArr[(M - 1) - j][i] = befArr[i][j];
		}
	}

	// -- ���� -- �Ѻ� 90�� ȸ���� N�� M�� ���� �ٲ��� ��.
	int temp{ N };
	N = M;
	M = temp;
}

void rotateArr5() {
	// �迭 ������ 5��
	copyArr(); // ����迭�� bef�迭�� ����

	// �׷� �й�
	grouping();

	//
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			switch (groupNum[i][j]) // � �׷��̳Ŀ� ���� �ٸ� ���
			{
			case 1:
				curArr[i][j + (M / 2)] = befArr[i][j];
				break;
			case 2:
				curArr[i + (N / 2)][j] = befArr[i][j];
				break;
			case 3:
				curArr[i][j - (M / 2)] = befArr[i][j];
				break;
			case 4:
				curArr[i - (N / 2)][j] = befArr[i][j];
				break;
			}
		}
	}
}

void rotateArr6() {
	// �迭 ������ 6��
	copyArr(); // ����迭�� bef�迭�� ����

	// �׷� �й�
	grouping();

	//
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			switch (groupNum[i][j]) // � �׷��̳Ŀ� ���� �ٸ� ���
			{
			case 1:
				curArr[i + (N / 2)][j] = befArr[i][j];
				break;
			case 2:
				curArr[i][j - (M / 2)] = befArr[i][j];
				break;
			case 3:
				curArr[i - (N / 2)][j] = befArr[i][j];
				break;
			case 4:
				curArr[i][j + (M / 2)] = befArr[i][j];
				break;
			}
		}
	}
}