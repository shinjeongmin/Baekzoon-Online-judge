#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int T, N, Answer;
int Matryoshka[501], dp[501];

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
		for (int i = 1; i <= N; i++) {
			dp[i] = 1;
			for (int j = 1; j <= i - 1; j++){
				if (Matryoshka[j] < Matryoshka[i]){
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			Answer = max(dp[i], Answer);
		}
		cout << Answer << "\n";
	}
}