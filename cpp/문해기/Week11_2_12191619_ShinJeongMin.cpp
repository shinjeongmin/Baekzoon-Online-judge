#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char paper[2000][2000];
int T, N;
struct paperInfo { // 빨간색 종이의 수의 크기, 파란색 종이의 수와 크기를 저장
	int redNumber, redSize, blueNumber, blueSize;
	paperInfo() { 
		redNumber = 0;
		redSize = 0;
		blueNumber = 0;
		blueSize = 0;
	};
};
paperInfo solution(int x, int y, int size);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 0; i <= N - 1; i++) {
			for (int j = 0; j <= N - 1; j++) {
				cin >> paper[i][j];
			}
		}
		paperInfo answer = solution(N - 1, N - 1, N);
		cout << answer.redNumber  << " " 
			<< answer.redSize  << " " 
			<< answer.blueNumber << " " 
			<< answer.blueSize << "\n";
	}
}

paperInfo solution(int x, int y, int size) { // x행 y열부터 size 크기 종이에서의 정답을 반환
	paperInfo ret = paperInfo();
	if (size == 1) {
		if (paper[x][y] == 'R')
		{
			ret.redNumber = 1;
			ret.redSize = 1;
		}
		else
		{
			ret.blueNumber = 1;
			ret.blueSize = 1;
		}
		return ret;
	}
	paperInfo status[5]; // 종이를 4개로 분할하여 각각 계산
	status[1] = solution(x, y, size / 2);
	status[2] = solution(x - size / 2, y, size / 2);
	status[3] = solution(x, y - size / 2, size / 2);
	status[4] = solution(x - size / 2, y - size / 2, size / 2);

	for (int i = 1; i <= 4; i++) {
		ret.redNumber += status[i].redNumber;
		ret.redSize += status[i].redSize;
		ret.blueNumber += status[i].blueNumber;
		ret.blueSize += status[i].blueSize;
	}
	if (ret.redNumber == 0) // 4개로 나눈 종이에 빨간색 종이가 없으면 큰 하나의 파란색 종이
		ret.blueNumber = 1;
	if (ret.blueNumber == 0) // 4개로 나눈 종이에 파란색 종이가 없으면 큰 하나의 빨간색 종이
		ret.redNumber = 1;
	return ret;
}

/*
2
4
R R B B
R R B B
R R R R
R R R R
8
R R R B B B B B
R R B B B B B B
B B B B B B B B
B B B B B B B B
R R R R R R R R
R R R R R R R R
B B B B R R R R
B B B B R R R R
*/