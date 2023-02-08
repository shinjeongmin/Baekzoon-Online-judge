#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void FailureFunction(string P);
bool KMPMatch(string T, string P);

int N, M;
string Puzzle[3000]; // 격자판
int F[3000]; // KMP 알고리즘 실패함수

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i <= N - 1; i++) {
		cin >> Puzzle[i];
	}

	string Text, Word; // 격자판을 합친 문자열(텍스트), 검색할 단어(패턴)
	for (int i = 0; i <= N - 1; i++) { // 격자판을 가로로 읽은 문자열
		Text += Puzzle[i];
		Text += "$";
	}
	for (int i = 0; i <= N - 1; i++) { // 격자판을 세로로 읽은 문자열
		for (int j = 0; j <= N - 1; j++) {
			Text += Puzzle[j][i];
		}
		Text += "$";
	}
	for (int i = 0; i <= N - 1; i++) { // 격자판을 대각선(좌상->우하 대각선의 윗부분)으로 읽은 문자열
		for (int j = 0; j <= N - i - 1; j++) {
			Text += Puzzle[j][i + j];
		}
		Text += "$";
	}
	for (int i = 1; i <= N - 1; i++) { // 격자판을 대각선(좌상->우하 대각선의 아랫부분)으로 읽은 문자열
		for (int j = 0; j <= N - i - 1; j++) {
			Text += Puzzle[i + j][j];
		}
		Text += "$";
	}

	for (int m = M; m > 0; m--) {
		cin >> Word; // 검색 단어 입력
		FailureFunction(Word); // KMP 알고리즘의 실패함수 계산
		if (KMPMatch(Text, Word)) // 검색 성공
			cout << 1 << "\n";
		else // 검색 실패
			cout << 0 << "\n";
	}
}

void FailureFunction(string P) {
	F[0] = 0;
	int i = 1;
	int j = 0;
	while (i < P.size()) {
		if (P[i] == P[j]) { // 두 문자가 일치하는 경우
			F[i] = j + 1; // P[0..i]내에서 일치하는 접두사와 진접미사의 최대 길이
			i++; // 다음 두 문자를 비교하기 위해
			j++;
		}
		else if (j > 0) // 패턴의 앞부분은 일치하다가 중간에 불일치 하는 경우
			j = F[j - 1]; // 실패 함수를 이용하여 시프트
		else // 패턴의 첫 번째 문자에서 불일치 하는 경우
		{
			F[i] = 0; // P[0]내에서 일치하는 접두사와 진접미사의 최대 길이는 0
			i++; // 나이브 알고리즘처럼 패턴을 오른쪽으로 한 칸 시프트
		}
	}
}

bool KMPMatch(string T, string P) {
	int i = 0;
	int j = 0;
	while (i < T.size()) {
		if (T[i] == P[j]) // 두 문자가 일치하는 경우
		{
			if (j == P.size() - 1) // 검색에 성공한 경우
				return true;
			i++; // 다음 두 문자를 비교하기 위해
			j++;
		}
		else if (j > 0) // 패턴의 앞부분은 일치하다가 중간에 불일치 하는 경우
			j = F[j - 1]; // 실패 함수를 이용하여 시프트
		else // 패턴의 첫 번째 문자에서 불일치하는 경우
			i++; // 나이브 알고리즘처럼 패턴을 오른쪽으로 한 칸 시프트
	}
	return false; // 검색 실패
}

/*
7 12
APPLEJF
BIOIKIA
MATWGRE
RNAHEGP
COTPQYE
ZIOLLEH
CNINEXU
PIG
SOLVE
APPLE
HELLO
EGG
OPERA
COIN
PIANO
POTATO
HOPE
NINE
YEAR
*/

/*
6 2
ABCABA
AACABA
AABAAB
BCCAAC
ABBCAA
ACABBC
ABAAB
AAACA
*/