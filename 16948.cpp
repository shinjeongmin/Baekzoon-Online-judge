#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int MAX = 200;
const int INF = 999999999;

typedef struct {
	int x, y;
}Div;

Div moveDiv[] = { {-2,-1}, {-2,1}, {0,-2}, {0,2}, {2,-1}, {2,1} };
int N;
pair<int, int> start, dest;
bool check[MAX][MAX];
int cache[MAX][MAX];

void initialize() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cache[i][j] = INF;
		}
	}
}

int BFS(int x,int y) {
	// 캐시 초기화
	initialize();

	// 큐를 생성 후 처음 위치 넣기
	queue<pair<int,int>> q;
	q.push(make_pair(x,y));

	// 처음위치는 이동횟수가 0
	cache[x][y] = 0;

	while (!q.empty()) {
		// 큐의 front를 현재 위치로 선정
		pair<int, int> curPos = q.front();
		q.pop();

		// 현재위치가 목적지와 일치하면 현재 위치의 캐시 반환
		if (curPos.first == dest.first &&
			curPos.second == dest.second) {
			return cache[curPos.first][curPos.second];
		}

		for (int i = 0; i < 6; i++) {
			// 다음위치 변수
			int nextX = curPos.first + moveDiv[i].x;
			int nextY = curPos.second + moveDiv[i].y;

			// 다음위치의 범위 및 탐색여부 확인
			if (0 <= nextX && nextX < N &&
				0 <= nextY && nextY < N && !check[nextX][nextY]) {
				// 다음위치 큐에 넣기
				q.push(make_pair(nextX, nextY));

				// 다음위치 탐색 설정
				check[nextX][nextY] = true;

				// 다음위치의 이동횟수를 기존값과 비교하여 재설정
				cache[nextX][nextY] = min(cache[nextX][nextY], cache[curPos.first][curPos.second] + 1);
			}
		}
	}
	// 이동할 수 없는 경우
	return -1;
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	memset(check, false, sizeof(check));

	cin >> N >> start.first >> start.second
		>> dest.first >> dest.second;
	cout << BFS(start.first, start.second) << "\n";

}
//제한시간 3:20