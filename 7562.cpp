#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int INF = 987654321;

typedef struct {
	int x, y;
}Dir;

int T, I;
pair<int, int> start, dest;
bool check[300][300];
int cache[300][300];
Dir moveDir[8] = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };

void init() {
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			cache[i][j] = INF;
		}
	}
}

int BFS(int firX, int firY) {
	init();

	queue<pair<int,int>> Q;

	// 첫번째 칸을 큐에 추가
	Q.push(make_pair(firX, firY));
	cache[firX][firY] = 0;

	while (!Q.empty()) {
		//큐에서 front 값을 현재 위치로 저장
		pair<int, int> curPos = Q.front();
		Q.pop();

		//현재칸이 목적지일 경우 목적지까지의 이동수를 반환
		if (curPos.first == dest.first &&
			curPos.second == dest.second)
			return cache[curPos.first][curPos.second];

		// 이동할 수 있는 총 8방향 반복문 실행
		for (int i = 0; i < 8; i++) {
			// 다음칸을 변수에 저장.
			int nextX = curPos.first + moveDir[i].x;
			int nextY = curPos.second + moveDir[i].y;

			// 만약 다음칸이 범위를 벗어나지 않고 가보지 않은 경우 큐에 추가
			if (0 <= nextX && nextX < I &&
				0 <= nextY && nextY < I && !check[nextX][nextY]) {
				Q.push(make_pair(nextX, nextY));
				// 다음칸을 탐색한 것으로 체크
				check[nextX][nextY] = true;
				// 최소 이동한 회수를 재설정 (기존값과 다음칸일때의 값 비교)
				cache[nextX][nextY] = min(cache[nextX][nextY], cache[curPos.first][curPos.second] + 1);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	cin >> T;
	
	for (int t = 0; t < T; t++) {
		memset(check, false, sizeof(check));

		cin >> I >> start.first >> start.second >> dest.first >> dest.second;
		cout << BFS(start.first, start.second) << "\n";
	}
	return 0;
}

//제한시간 10:20