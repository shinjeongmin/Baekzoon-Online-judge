#include<iostream>
#include<vector>
#include<queue>
using namespace std;

queue<int> computer[100 + 1];
bool check[100 + 1];
int InfectedComputers;

void warmInfect(int n) {
	check[n] = true;

	// 큐에 먼저담긴 순서로 탐색
	if (!check[computer[n].front()]) { //탐색하지 않았으면
		warmInfect(computer[n].front());
		computer[n].pop();
		InfectedComputers++;
	}
	else { //탐색했다면 그냥 지나가
		computer[n].pop();
	}

	// 큐가 빌 때까지 재귀
	if (!computer[n].empty()) {
		warmInfect(n);
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	int N,M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int com1, com2;
		cin >> com1 >> com2;

		// 서로 노드를 연결 시켜준다.
		computer[com1].push(com2);
		computer[com2].push(com1);
	}

	for (int i = 1; i <= 1; i++) {
		warmInfect(i);
	}

	cout << InfectedComputers;
}