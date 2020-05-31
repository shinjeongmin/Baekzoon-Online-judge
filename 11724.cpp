#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#include <unordered_set>
using namespace std;

vector<int> v;
vector<vector<int>> vec;
bool check[1001];
stack<int> s;

int dfs(int n, int count) {
	// dfs해서 연결되어있는 노드들은 모두 탐색처리

	s.push(n);
	while (!s.empty())
	{
		n = s.top();
		s.pop();
		for (int i = 0; i < vec[n].size(); i++)
		{
			if (!check[vec[n][i]]) // 탐색을 안한 연결노드라면
			{
				//스택에 추가
				s.push(vec[n][i]);
				check[vec[n][i]] = true; // 탐색체크
			}
		}
	}

	return ++count;
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	int N, M, count{ 0 };
	cin >> N >> M;

	vec.assign(N + 1, v); //인덱스 0을 제외하므로 1추가

	// 정점과 간선 배치
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v); // 정방향
		vec[v].push_back(u); // 반대방향
	}

	// 인덱스 순서대로 탐색을 이미 한 노드인지 확인하여 dfs 진행
	for (int i = 1; i <= N; i++)
	{
		if (check[i]) // 이미 탐색을 진행한 노드라면 패스
			continue;
		count = dfs(i, count); // dfs를 실행한 만큼 카운터 증가
	}

	cout << count << "\n";
}
/*

*/