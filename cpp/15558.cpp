#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct str { 
	int line; // 왼쪽 열, 오른쪽 열 (줄)
	int current_idx; // 현재 인덱스 (칸)
	int start_idx; // 시작지점 인덱스
	str(int line, int current_idx, int start_idx) // str 구조체 생성자
		: line(line), current_idx(current_idx), start_idx(start_idx) {

	}
};

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	char c;
	vector<vector<int>> vec(2, vector<int>(N + 1, 0)); // 각각의 기둥의 칸이 안전한 칸인지 여부
	vector<vector<int>> visit(2, vector<int>(N + 1, 0)); // 각 기둥의 칸을 방문했는지 여부 저장

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> c; // 1101을 연속적으로 받지만 각각 개별의 인자로 받아야 하므로 char 사용
			vec[i][j] = (int)c - 48; // 아스키 코드 응용
		}
	}

	int ans = 0; // 가능여부 결과
	queue<str> q; // 구조체로 이루어진 큐
	q.push(str(0, 1, 1));

	while (!q.empty()) {
		int line = q.front().line; // 0:왼쪽 열, 1:오른쪽 열
		int current_idx = q.front().current_idx; // 현재 index
		int start_idx = q.front().start_idx; // 시작지점 index
		q.pop();

		if (current_idx > N) { // 현재 인덱스가 N을 넘어가면 끝난다.
			ans = 1;
			break;
		}

		//이미 확인했는지 체크
		if (visit[line][current_idx])
			continue;

		visit[line][current_idx] = 1; // 방문여부를 체크함

		// 1. 한칸 앞으로 이동
		// 현재 인덱스 +1이 N을 넘거나 또는 이동할 다음 인덱스가 안전한 칸인 경우
		if (current_idx + 1 > N || vec[line][current_idx + 1] == 1) {
			// 다음칸을 큐에 저장하고 시작지점을 +1해서 가장 밑 칸을 한 칸 없앰
			q.push(str(line, current_idx + 1, start_idx + 1)); 
		}

		// 2. 한칸 뒤로 이동
		// 바로 뒤칸이 사라질 칸인 시작인덱스보다 1이상 크고, 안전한 칸인 경우
		if (current_idx - 1 >= start_idx + 1 &&
			vec[line][current_idx - 1] == 1) {
			// 뒷 칸을 큐에 저장하고 시작지점은 +1해서 가장 밑 칸을 없앰
			q.push(str(line, current_idx -1, start_idx + 1));
		}

		// 3.반대편 줄로 점프
		// 현재 0이면 1, 1이면 0 으로 줄 이동
		line = (line == 0) ? 1 : 0;
		// +K칸이 N을 넘거나, K칸 이동하는 칸이 안전한 칸일 경우
		if (current_idx + K > N || vec[line][current_idx + K] == 1) {
			// +K칸을 큐에 저장하고 시작지점을 +1해서 가장 밑 칸 삭제
			q.push(str(line, current_idx + K, start_idx + 1));
		}
	}

	cout << ans << endl;
	return 0;
}
//제한시간 3:30