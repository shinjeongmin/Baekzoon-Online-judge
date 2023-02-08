#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solution();

int score[23 + 1]; // score[i] : i번째 영어 단어의 점수
int needAlphabet[23 + 1][26 + 1]; 
// alphabet[i][j] : i번째 영어 단어를 만들기 위해 필요한 j번째 알파벳의 개수

int restAlphabet[9999999][26 + 1]; // dp[k][j] : k에 대응되는 상황에서 j번째 알파벳의 남은 개수
int M, answer;
string word;
int getScore[9999999]; // getScore[i] : i에 대응되는 상황에서 얻는 점수

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 26; i++) {
		cin >> restAlphabet[0][i]; // 초기 상태에서 갖고 있는 알파벳의 수
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> word >> score[i]; // i번째 영어 단어와 영어 단어를 생성했을 때 얻게 되는 점수

		for (int j = 0; j < word.length(); j++) {
			needAlphabet[i][word[j] - 'a' + 1] += 1;
		}
	}
	solution();
	cout << answer << "\n";
}

void solution() {
	getScore[0] = 0; // 0개의 영어 단어를 만드는 경우의 점수는 0
	for (int i = 1; i <= M; i++) {
		int status = 1 << (i - 1); // i번째 영어 단어를 만드는 경우 상태를 나타내는 정수
		// (M이 3인 경우, 001, 010, 100 이 각 status에 들어감)
		for (int j = 0; j <= status - 1; j++) { // status의 이전 상태에서 i번째 영어 단어를 추가함
			bool flag = false;
			for (int k = 1; k <= 26; k++) { // 단어를 만들 수 있는 각 알파벳이 충분한지 확인
				if (restAlphabet[j][k] < needAlphabet[i][k]) {
					// j에 대응되는 상황에서 알파벳이 부족해서 i번째 영어 단어를 못 만드는 경우 flag 변경
					flag = true;
				}
			}
			if (flag == true) 
				continue;
			for (int k = 1; k <= 26; k++) 
				restAlphabet[j + status][k] = restAlphabet[j][k] - needAlphabet[i][k];
			getScore[j + status] = getScore[j] + score[i]; 
			// j + status 는 이전 것(j)에서 i번째 단어를 추가한 것(+status)으로 건너뛰기 
			answer = max(answer, getScore[j + status]);
		}
	}
}

/*
3 1 0 0 2 0 0 0 0 0 0 0 0 2 0 0 0 0 2 0 0 0 0 0 0 0
3
banana 5
bane 4
nas 4
*/