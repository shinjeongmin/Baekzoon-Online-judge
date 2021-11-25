#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solution();

int score[23 + 1];
int needAlphabet[23 + 1][26 + 1];

int restAlphabet[9999999][26 + 1];
int M, answer;
string word;
int getScore[9999999];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 26; i++) {
		cin >> restAlphabet[0][i];
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> word >> score[i];

		for (int j = 0; j < word.length(); j++) {
			needAlphabet[i][word[j] - 'a' + 1] += 1;
		}
	}
	solution();
	cout << answer << "\n";
}

void solution() {
	getScore[0] = 0;
	for (int i = 1; i <= M; i++) {
		int status = 1 << (i - 1);
		for (int j = 0; j <= status - 1; j++) {
			bool flag = false;
			for (int k = 1; k <= 26; k++) {
				if (restAlphabet[j][k] < needAlphabet[i][k]) {
					flag = true;
				}
			}
			if (flag == true) 
				continue;
			for (int k = 1; k <= 26; k++) 
				restAlphabet[j + status][k] = restAlphabet[j][k] - needAlphabet[i][k];
			getScore[j + status] = getScore[j] + score[i];
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