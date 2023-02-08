#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int T, A, B;
vector<int> road[10000]; // road[A] : A�� �濡�� �̵��� �� �ִ� ���� ��ȣ�� ����
int check[10000];
queue<int> que; // BFS �˰��򿡼� ����� ť

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i <= 9999; i++) { // i�� �濡�� �̵��� �� �ִ� ���� ��ȣ�� ���
		if (i != 0) {
			road[i].push_back(i - 1);
		}
		if (i != 9999) {
			road[i].push_back(i + 1);
		}
		int num = 0, temp = i; // ���ȣ�� �������� ������ ��ȣ�� ��
		for (int j = 0; j <= 3; j++) {
			num = num * 10 + temp % 10;
			temp = temp / 10;
		}
		road[i].push_back(num);
	}

	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i <= 9999; i++) {
			check[i] = 10000;
		}
		cin >> A >> B;
		check[A] = 0;
		que.push(A);
		while (que.empty() == false) { // ť�� ���̻� ���Ұ� ������ ����
			int now = que.front();
			que.pop();
			for (int i = 0; i < road[now].size(); i++) { // now�� �濡�� �̵��� �� �ִ� ������ �̵�
				if (check[road[now][i]] > check[now] + 1) { // �湮���� ���� ���� ť�� ����
					que.push(road[now][i]);
					check[road[now][i]] = check[now] + 1;
				}
			}
		}
		cout << check[B] << "\n";
	}
}