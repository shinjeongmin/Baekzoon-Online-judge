#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N, M, A, B, Answer;
vector<int> graph[100 + 1]; // 인접리스트 그래프
int visit[100 + 1]; // 방문 노드 체크 배열

void init() {
	for (int i = 1; i <= 100; i++) {
		graph[i].clear();
		visit[i] = 0;
	}
}

void dfs(int idx) {
	visit[idx] = 1; // 방문 처리
	for (int i = 0; i < graph[idx].size(); i++) { // 해당 인덱스에 연결된 모든 노드들 인덱스 방문
		int v = graph[idx][i];
		if (visit[v] == 0)
			dfs(v); // 방문하지 않은 경우 방문
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		init();
		cin >> N >> M; // 공의 개수, 비교 횟수
		for (int i = 1; i <= M; i++) {
			cin >> A >> B; // A가 B보다 무거움
			graph[A].push_back(B); // A -> B 방향 간선 추가
		}

		for (int i = 1; i <= N; i++) { // 각각의 공에 대해서 그래프
			for (int j = 1; j <= N; j++) { // 방문 초기화
				visit[j] = 0;
			}
			dfs(i); // 각 공에 대해 dfs하여 방문할 수 있는(i보다 가벼운) 수 구함
			Answer = 0;
			for (int j = 1; j <= N; j++) { // 방문한 개수 구하기
				Answer = Answer + visit[j];
			}
			cout << Answer - 1 << " ";
		}
		cout << "\n";
	}
}

/*
2
6 7
1 2
1 3
3 4
3 6
5 2
5 6
6 4
7 9
1 2
1 5
2 3
5 3
5 6
6 3
3 4
6 7
7 4
*/