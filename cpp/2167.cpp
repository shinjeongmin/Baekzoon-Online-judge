#include <iostream>
using namespace std;

int main() {
	int N, M, K, i, j, x, y;
	int result{ 0 };

	cin >> N >> M;

	int arr[300][300] = {}; // 배열

	for (int i = 0; i < N; i++){ //해당 인덱스에 대응하는 배열에 숫자 넣기
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			arr[i][j] = temp;
		}
	}

	cin >> K; // 합을 구할 부분의 개수

	for (int k = 0; k < K; k++) {
		cin >> i >> j >> x >> y; //두 좌표 입력

		result = 0; //합 초기화

		for (int i2 = i; i2 <= x; i2++) {
			for (int j2 = j; j2 <= y; j2++) {
				result += arr[i2 - 1][j2 - 1]; //배열은 (0,0)부터 시작이므로 1씩 뺀 좌표값을 사용.
			}
		}
		cout << result <<  "\n";
	}
}