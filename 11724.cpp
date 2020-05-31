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
	// dfs�ؼ� ����Ǿ��ִ� ������ ��� Ž��ó��

	s.push(n);
	while (!s.empty())
	{
		n = s.top();
		s.pop();
		for (int i = 0; i < vec[n].size(); i++)
		{
			if (!check[vec[n][i]]) // Ž���� ���� ��������
			{
				//���ÿ� �߰�
				s.push(vec[n][i]);
				check[vec[n][i]] = true; // Ž��üũ
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

	vec.assign(N + 1, v); //�ε��� 0�� �����ϹǷ� 1�߰�

	// ������ ���� ��ġ
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v); // ������
		vec[v].push_back(u); // �ݴ����
	}

	// �ε��� ������� Ž���� �̹� �� ������� Ȯ���Ͽ� dfs ����
	for (int i = 1; i <= N; i++)
	{
		if (check[i]) // �̹� Ž���� ������ ����� �н�
			continue;
		count = dfs(i, count); // dfs�� ������ ��ŭ ī���� ����
	}

	cout << count << "\n";
}
/*

*/