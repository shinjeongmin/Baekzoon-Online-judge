#include<iostream>
#include<queue>
using namespace std;

const int MAX = 100;

struct triple {
	triple(int x, int y, int z)
		:x(x), y(y), z(z)
	{ }
	int x, y, z;
};

triple moveDir[6] = { {1,0,0}, {-1,0,0}, {0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };

int M, N, H;
int tomato[MAX][MAX][MAX];
queue<triple>q;
int noTomato;

// 토마토가 전부 익었는지 확인
bool allRipe() {
	int possible = M * N * H - noTomato; // 전체 토마토개수 - 썩은 토마토 개수
	int cnt = 0; // 현재 익은 토마토 개수

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (tomato[k][j][i] == 1)
					cnt++;
			}
		}
	}
	return possible == cnt; // 익을 수 있는 토마토가 모두 익었는가?
}

int BFS() {
	int day = 0;

	// 처음부터 익힐 수 있는 토마토가 없는 경우
	while (q.empty()) {
		return -1;
	}
	
	while (!q.empty()) {
		int currentSize = q.size(); // 큐에 들어있는 개수만큼 반복문 (하루일차 모든 토마토가 익음을 전파)
		
		for (int i = 0; i < currentSize; i++) {
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().z;

			for (int i = 0; i < 6; i++) {
				int nextX = x + moveDir[i].x;
				int nextY = y + moveDir[i].y;
				int nextZ = z + moveDir[i].z;

				// 다음 토마토가 범위 안에 있고 안 익었을 경우에만
				if (0 <= nextX && nextX < M &&
					0 <= nextY && nextY < N &&
					0 <= nextZ && nextZ < H &&
					tomato[nextX][nextY][nextZ] == 0) {
					tomato[nextX][nextY][nextZ] = 1; // 방문 체크
					q.push(triple(nextX, nextY, nextZ)); // 다음 토마토 위치 큐에 저장
				}
			}
			q.pop();
			
			// 익힐 수 있는 토마토를 전부 익혔고, 전부 익었을 경우
			if (q.size() == 0 && allRipe())
				return day;
			// 익힐 수 있는 토마토는 전부 익혔지만, 안 익은 토마토가 있을 경우
			/*else if (q.size() == 0 && !allRipe())
				return -1;*/
		}
		day++;
	}
	return -1;
}

int main() {
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++) {
				cin >> tomato[k][j][i];
				if (tomato[k][j][i] == 1)
					q.push(triple(k, j, i)); // 익은 토마토는 큐에 넣는다.
				if (tomato[k][j][i] == -1)
					noTomato++; // 토마토를 넣을 수 없는 칸
			}

	if (q.size() == M * N * H - noTomato)
	{
		cout << 0 << endl; // 모든 토마토 다 익었을 경우
	}
	else {
		int result = BFS();
		cout << result << endl;
	}
}
// 제한시간 9:20