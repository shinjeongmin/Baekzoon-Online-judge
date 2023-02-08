#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int T, N, Answer;
int Matryoshka[501], dp[501]; // 마트료시카의 크기 및 최대 조립 개수를 저장한 배열

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 1; i <= N; i++) { 
			cin >> Matryoshka[i];
		}
		Answer = 0;
		for (int i = 1; i <= N; i++) { // i번 마트료시카가 마지막으로 선택될 때, 최대 조립 개수 계산
			dp[i] = 1;
			for (int j = 1; j <= i - 1; j++){ // j번 마트료시카가 i번 보다 크기가 작다면
				if (Matryoshka[j] < Matryoshka[i]){ // 1번~j번의 최대 조립개수 +1 과 비교하여
					dp[i] = max(dp[i], dp[j] + 1); // 큰 값으로 업데이트
				}
			}
			Answer = max(dp[i], Answer);
		}
		cout << Answer << "\n";
	}
}