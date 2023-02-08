#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// void printTri(); // test
void init();

int T, N;
int triangle[100 + 1][100 + 1]; // 삼각형에 전힌 숫자를 저장
int resultTri[100 + 1][100 + 1]; // i행 j번째 수까지 최단 삼각형 경로의 길이를 저장

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		init();

		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= i; j++) {
				cin >> triangle[i][j]; // 삼각형 입력
			}
		}

		resultTri[1][1] = triangle[1][1]; // 첫번째 칸 경로 설정

		for (int i = 1; i < N; i++) {
			for (int j = 1; j <= i; j++) {
				if (resultTri[i + 1][j] == 0) { // 다음 위치(왼쪽 아래)의 경로가 설정되지 않은 경우
					resultTri[i + 1][j] = triangle[i + 1][j] + resultTri[i][j]; 
					// 다음 위치의 삼각형 번호(i+1,j) + 현재 위치의 경로 합(i,j)
				}
				else { // 이미 경로값이 있는 경우
					resultTri[i + 1][j] =
						min(resultTri[i + 1][j], triangle[i + 1][j] + resultTri[i][j]);
					// 이미 있는 값과 다음 위치의 삼각형 번호 + 현재 위치의 경로 합 중 작은 것
				}
				resultTri[i + 1][j + 1] = triangle[i + 1][j + 1] + resultTri[i][j];
				// 다음 열(오른쪽 아래. i+1,j+1)은 항상 비어있으므로 
				// 삼각형 번호 + 현재 위치 경로 넣기
			}
		}

		cout << *min_element(resultTri[N] + 1, resultTri[N] + N + 1) << "\n";
		// printTri();
	}
}

void init() {
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			triangle[i][j] = 0;
			resultTri[i][j] = 0;
		}
	}
}

//void printTri() {
//	cout << "출력 --- \n";
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= i; j++) {
//			cout << resultTri[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	cout << "end --- \n";
//}

/*
3
5
2
3 4
7 5 6
1 3 2 8
9 10 5 7 1
5
7
5 2
13 6 8
1 2 5 9
10 5 4 1 17
1
1
*/