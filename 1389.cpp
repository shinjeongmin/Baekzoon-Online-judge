#include<iostream>
#include<algorithm>
using namespace std;

const int INF = 10000;
const int MAX = 101;

int N, M;
int graph[MAX][MAX];

//플로이드 알고리즘;
void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) //자기 자신으로 가는 것 (loop)는 제외 (loop에 들어있는 값은 0)
					continue;
				// 만약 i에서 j로 가는 경로중 k가 사이에 있으면
				else if (graph[i][k] && graph[k][j]) {
					if (graph[i][j] == 0) { // 처음 값이 매겨지는 곳이라면 (여러번 거쳐가는 곳임)
						graph[i][j] = graph[i][k] + graph[k][j]; // 중간과정의 가중치를 포함한 값을 저장.
					}
					else { // 이미 값이 있는 곳이라면 더 작은 값을 저장
						graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = graph[b][a] = 1;
	}

	floyd();

	int Minresult = INF;
	int Minperson;
	for (int i = 1; i < N; i++) {
		int sum = 0;

		// 해당 인덱스(i)번째 사람의 케빈 베이컨 값을 구하기
		for (int j = 1; j <= N; j++) {
			sum += graph[i][j];
		}
		if (Minresult > sum) // 최소 베이컨 수 보다 현재 인덱스 사람의 케빈 베이컨값이 작으면
		{
			Minresult = sum;
			Minperson = i;
		}
	}

	cout << Minperson << "\n";
}