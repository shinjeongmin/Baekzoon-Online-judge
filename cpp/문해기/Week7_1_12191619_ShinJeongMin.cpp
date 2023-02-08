#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N, M, A, B, Answer;
vector<int> graph[100 + 1]; // ��������Ʈ �׷���
int visit[100 + 1]; // �湮 ��� üũ �迭

void init() {
	for (int i = 1; i <= 100; i++) {
		graph[i].clear();
		visit[i] = 0;
	}
}

void dfs(int idx) {
	visit[idx] = 1; // �湮 ó��
	for (int i = 0; i < graph[idx].size(); i++) { // �ش� �ε����� ����� ��� ���� �ε��� �湮
		int v = graph[idx][i];
		if (visit[v] == 0)
			dfs(v); // �湮���� ���� ��� �湮
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		init();
		cin >> N >> M; // ���� ����, �� Ƚ��
		for (int i = 1; i <= M; i++) {
			cin >> A >> B; // A�� B���� ���ſ�
			graph[A].push_back(B); // A -> B ���� ���� �߰�
		}

		for (int i = 1; i <= N; i++) { // ������ ���� ���ؼ� �׷���
			for (int j = 1; j <= N; j++) { // �湮 �ʱ�ȭ
				visit[j] = 0;
			}
			dfs(i); // �� ���� ���� dfs�Ͽ� �湮�� �� �ִ�(i���� ������) �� ����
			Answer = 0;
			for (int j = 1; j <= N; j++) { // �湮�� ���� ���ϱ�
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