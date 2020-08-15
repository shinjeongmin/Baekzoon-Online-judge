#include<iostream>
#include<queue>
using namespace std;

const int MAX = 1000000 + 1;
int F, S, G, U, D;
int cache[MAX];

int BFS() {
	queue<int> q;
	q.push(S); // 큐에 시작하는 층수를 push
	cache[S] = 1; // 시작하는 층 cache에 왜 1을 담지?

	while (!q.empty()) {
		int curFloor = q.front(); // 현재 층 변수를 만들어서 큐의 가장 위 값을 담음
		q.pop();

		// 목표층에 도달하면
		if (curFloor == G)
			return cache[curFloor] - 1; // 현재 층 인덱스인 cache에서 1을 뺀 값을 반환 / 왜?

		// 위로 U층, 아래로 D층 갈 수 있다.
		int nextFloor[2] = { curFloor + U, curFloor - D }; // U만큼 위로 올라간 층, D만큼 내려간 층 두 값이 담긴 배열
		for (int i = 0; i < 2; i++) {
			// 범위 내에 있고 이미 도달한 층이 아닐 경우에만 update
			if (1 <= nextFloor[i] && nextFloor[i] <= F &&
				cache[nextFloor[i]] == 0) {
				cache[nextFloor[i]] = cache[curFloor] + 1; // 다음에 가게될 층수 cache에 +1 (그냥 1을 대입해도 되지 않나?)
				q.push(nextFloor[i]);
			}
		}
	}
	return -1; // 목표 층에 도달하지 못하면
}

int main() {
	cin >> F >> S >> G >> U >> D;

	int result = BFS();
	if (result == -1)
		cout << "use the stairs" << endl;
	else
		cout << result << endl;
	return 0;
}
// 제한시간 10:20