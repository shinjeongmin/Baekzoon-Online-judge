#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;
		string stdWord[20][100];
		int stdWordCnt[20];
		string profSay[2000];
		for (int i = 0; i < M; i++) {// 교수님 단어
			cin >> profSay[i];
		}
		for (int i = 0; i < N; i++) { // 학생 명수
			int temp;
			cin >> temp;
			stdWordCnt[i] = temp;
			for (int j = 0; j < temp; j++) { // 학생당 문장들
				cin >> stdWord[i][j];
			}
		}

		// 조건1 : 첫 단어를 가장먼저 쓴 사람 존재
		bool condition1 = false;
		string firstWord = profSay[0];
		for (int i = 0; i < N; i++) {
			if (stdWord[i][0] == firstWord)
				condition1 = true;
		}

		// 조건2 : 모든 단어의 포함 
		bool condition2 = true;
		int stdIdx[20][100] = { 0, };
		int stdCurIdx[20] = { 0, };
		for (int i = 0; i < M; i++) {
			// 한 단어 마다 포함여부 확인
			bool checkWordHave = false;
			for (int j = 0; j < N; j++) {
				if (stdWord[j][stdCurIdx[j]] == profSay[i]) // 포함된 경우
				{
					checkWordHave = true;
					stdIdx[j][stdCurIdx[j]] = i + 1; // 인덱스 오름차순
					stdCurIdx[j]++;
				}
			}
			if (checkWordHave == false)
			{
				condition2 = false;
				break;
			}
		}

		// 조건3 : 인덱스 오름차순 + 없는 단어(0) 중간에 없음
		bool condition3 = true;
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < stdWordCnt[i]; j++) {
				// 0이 숫자들 중간에 껴있지 않음
				if (stdIdx[i][j - 1] == 0 && stdIdx[i][j] != 0)
				{
					condition3 = false;
				}
			}
		}

		// 조건 부합의 경우
		if (condition1 && condition2 && condition3)
			cout << 1;
		else
		{
			cout << 0;
		}
		cout << "\n";

		continue;

		//test 출력
		for (int i = 0; i < N; i++) {
			cout << i << " ";
			for (int j = 0; stdWord[i][j] != ""; j++) {
				cout << stdWord[i][j] << " " << j << " ";
			}
			cout << "\n";
			for (int j = 0; stdWord[i][j] != ""; j++) {
				cout << stdIdx[i][j] << " ";
			}
			cout << "\n\n";
		}
	}
}