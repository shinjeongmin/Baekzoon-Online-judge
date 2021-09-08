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

bool check_s[1000 + 1]; // �ε��� ���� : ���� ���� +1
bool check_q[1000 + 1]; // �ε��� ���� : ���� ���� +1
vector<int> tempv;
vector<vector<int>> v(10000, tempv);
stack<int> s;
queue<int> q;

void dfs(int n) {
	/* �ʿ���� �κ� �̰� �־ �ؿ��� ó���� ���־�� ����
	if (!v[n].size())
		return;
	*/
	cout << n << " ";
	for (int i = 0; i < v[n].size(); i++)
	{
		if (!check_s[v[n][i]])
		{
			check_s[v[n][i]] = true; // Ž�� üũ
			dfs(v[n][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	int N, M, V, root;
	cin >> N >> M >> root;

	// ���� �Է� (index)
	for (int i = 0; i < M; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		v[n1].push_back(n2); //������ ����
		v[n2].push_back(n1); //�ݴ���� ����
	}

	// �ι�° �ε��� �������� ����
	for (int i = 0; i < v.size(); i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	V = root;
	// DFS
	check_s[V] = true;

	//************ ��忡�� ���� ����� ������ ���� ��� ����ó�� ******************
	/*
	3 1 1
	2 3
	*/
	/*
	  1

	2 - 3
	(�̷� ���)
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
		V = q.front(); // ���� �� ���� ��带 ����.
		cout << q.front() << " ";
		q.pop();
		for (int i = 0; i < v[V].size(); i++)
		{ //���� ������ŭ �ݺ�
			if (!check_q[v[V][i]])
			{
				q.push(v[V][i]); // ���ÿ� ��� �߰�
				check_q[v[V][i]] = true; //Ž�� üũ
			}
		}
	}
}

/*
*/