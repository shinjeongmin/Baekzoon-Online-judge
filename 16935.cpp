#include <iostream>
#include <algorithm>
using namespace std;
int befArr[100][100]; // 배열을 돌릴 때 기존의 배열을 담음
int curArr[100][100]; // 배열을 돌릴 때 돌려진 배열을 담음
int groupNum[100][100]; // 5,6번에서 4개의 부분으로 나눌 때 그룹번호를 담는 배열
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
	// 배열 입력함수
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> curArr[i][j];
		}
	}

}

void printArr() {
	// 배열 출력함수
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
	//befArr 0으로 초기화
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			befArr[i][j] = 0;
		}
	}

	// cur배열의 값을 before 배열로 복사.
	copy(&curArr[0][0], &curArr[0][0] + (100 * 100), &befArr[0][0]);
	
	//curArr 0으로 초기화
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			curArr[i][j] = 0;
		}
	}
}

void grouping() {
	//0으로 초기화
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			groupNum[i][j] = 0;
		}
	}

	// 그룹번호를 그룹번호배열에 넣기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i < N / 2){
				// 1,2 그룹
				if (j < M / 2) // 1 그룹
					groupNum[i][j] = 1;
				else // 2 그룹
					groupNum[i][j] = 2;
			}
			else {
				// 3,4 그룹
				if (j < M / 2) // 4 그룹
					groupNum[i][j] = 4;
				else // 3 그룹
					groupNum[i][j] = 3;
			}
		}
	}
}

void rotateArr1() {
	// 배열 돌리기 1번
	copyArr(); // 현재배열을 bef배열로 복사

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			curArr[(N - 1) - i][j] = befArr[i][j];
		}
	}
}

void rotateArr2() {
	// 배열 돌리기 2번
	copyArr(); // 현재배열을 bef배열로 복사

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			curArr[i][(M - 1) - j] = befArr[i][j];
		}
	}
}

void rotateArr3() {
	// 배열 돌리기 3번
	copyArr(); // 현재배열을 bef배열로 복사

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			curArr[j][(N - 1) - i] = befArr[i][j];
		}
	}

	// -- 주의 -- 한변 90도 회전시 N와 M의 값은 바뀌어야 함.
	int temp{ N };
	N = M;
	M = temp;
}

void rotateArr4() {
	// 배열 돌리기 4번
	copyArr(); // 현재배열을 bef배열로 복사

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			curArr[(M - 1) - j][i] = befArr[i][j];
		}
	}

	// -- 주의 -- 한변 90도 회전시 N와 M의 값은 바뀌어야 함.
	int temp{ N };
	N = M;
	M = temp;
}

void rotateArr5() {
	// 배열 돌리기 5번
	copyArr(); // 현재배열을 bef배열로 복사

	// 그룹 분배
	grouping();

	//
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			switch (groupNum[i][j]) // 어떤 그룹이냐에 따라 다른 방식
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
	// 배열 돌리기 6번
	copyArr(); // 현재배열을 bef배열로 복사

	// 그룹 분배
	grouping();

	//
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			switch (groupNum[i][j]) // 어떤 그룹이냐에 따라 다른 방식
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