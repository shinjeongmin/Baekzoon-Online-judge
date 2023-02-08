#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void solution();

int score[23 + 1]; // score[i] : i��° ���� �ܾ��� ����
int needAlphabet[23 + 1][26 + 1]; 
// alphabet[i][j] : i��° ���� �ܾ ����� ���� �ʿ��� j��° ���ĺ��� ����

int restAlphabet[9999999][26 + 1]; // dp[k][j] : k�� �����Ǵ� ��Ȳ���� j��° ���ĺ��� ���� ����
int M, answer;
string word;
int getScore[9999999]; // getScore[i] : i�� �����Ǵ� ��Ȳ���� ��� ����

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 26; i++) {
		cin >> restAlphabet[0][i]; // �ʱ� ���¿��� ���� �ִ� ���ĺ��� ��
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> word >> score[i]; // i��° ���� �ܾ�� ���� �ܾ �������� �� ��� �Ǵ� ����

		for (int j = 0; j < word.length(); j++) {
			needAlphabet[i][word[j] - 'a' + 1] += 1;
		}
	}
	solution();
	cout << answer << "\n";
}

void solution() {
	getScore[0] = 0; // 0���� ���� �ܾ ����� ����� ������ 0
	for (int i = 1; i <= M; i++) {
		int status = 1 << (i - 1); // i��° ���� �ܾ ����� ��� ���¸� ��Ÿ���� ����
		// (M�� 3�� ���, 001, 010, 100 �� �� status�� ��)
		for (int j = 0; j <= status - 1; j++) { // status�� ���� ���¿��� i��° ���� �ܾ �߰���
			bool flag = false;
			for (int k = 1; k <= 26; k++) { // �ܾ ���� �� �ִ� �� ���ĺ��� ������� Ȯ��
				if (restAlphabet[j][k] < needAlphabet[i][k]) {
					// j�� �����Ǵ� ��Ȳ���� ���ĺ��� �����ؼ� i��° ���� �ܾ �� ����� ��� flag ����
					flag = true;
				}
			}
			if (flag == true) 
				continue;
			for (int k = 1; k <= 26; k++) 
				restAlphabet[j + status][k] = restAlphabet[j][k] - needAlphabet[i][k];
			getScore[j + status] = getScore[j] + score[i]; 
			// j + status �� ���� ��(j)���� i��° �ܾ �߰��� ��(+status)���� �ǳʶٱ� 
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