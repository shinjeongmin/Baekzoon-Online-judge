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

bool check_s[1000 + 1]; // 인덱스 갯수 : 정점 갯수 +1
bool check_q[1000 + 1]; // 인덱스 갯수 : 정점 갯수 +1
vector<int> tempv;
vector<vector<int>> v(10000, tempv);
stack<int> s;
queue<int> q;

void dfs(int n) {
	/* 필요없는 부분 이게 있어서 밑에서 처리를 해주어야 했음
	if (!v[n].size())
		return;
	*/
	cout << n << " ";
	for (int i = 0; i < v[n].size(); i++)
	{
		if (!check_s[v[n][i]])
		{
			check_s[v[n][i]] = true; // 탐색 체크
			dfs(v[n][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	int N, M, V, root;
	cin >> N >> M >> root;

	// 정점 입력 (index)
	for (int i = 0; i < M; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		v[n1].push_back(n2); //정방향 간선
		v[n2].push_back(n1); //반대방향 간선
	}

	// 두번째 인덱스 오름차순 정렬
	for (int i = 0; i < v.size(); i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	V = root;
	// DFS
	check_s[V] = true;

	//************ 노드에서 직접 연결된 간선이 없는 경우 예외처리 ******************
	/*
	3 1 1
	2 3
	*/
	/*
	  1

	2 - 3
	(이런 모양)
	*/
	/*if (!v[V].size())
	{
		cout << V;
	}
	else*/
	dfs(V);

	cout << "\n";

	V = root;
	// BFS
	q.push(V);
	check_q[V] = true;
	while (!q.empty())
	{
		V = q.front(); // 스택 맨 위의 노드를 꺼냄.
		cout << q.front() << " ";
		q.pop();
		for (int i = 0; i < v[V].size(); i++)
		{ //간선 갯수만큼 반복
			if (!check_q[v[V][i]])
			{
				q.push(v[V][i]); // 스택에 노드 추가
				check_q[v[V][i]] = true; //탐색 체크
			}
		}
	}
}

/*
*/