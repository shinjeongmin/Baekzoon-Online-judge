#include<iostream>
#include<queue>
using namespace std;

const int MAX = 1000000 + 1;
int F, S, G, U, D;
int cache[MAX];

int BFS() {
	queue<int> q;
	q.push(S); // ť�� �����ϴ� ������ push
	cache[S] = 1; // �����ϴ� �� cache�� �� 1�� ����?

	while (!q.empty()) {
		int curFloor = q.front(); // ���� �� ������ ���� ť�� ���� �� ���� ����
		q.pop();

		// ��ǥ���� �����ϸ�
		if (curFloor == G)
			return cache[curFloor] - 1; // ���� �� �ε����� cache���� 1�� �� ���� ��ȯ / ��?

		// ���� U��, �Ʒ��� D�� �� �� �ִ�.
		int nextFloor[2] = { curFloor + U, curFloor - D }; // U��ŭ ���� �ö� ��, D��ŭ ������ �� �� ���� ��� �迭
		for (int i = 0; i < 2; i++) {
			// ���� ���� �ְ� �̹� ������ ���� �ƴ� ��쿡�� update
			if (1 <= nextFloor[i] && nextFloor[i] <= F &&
				cache[nextFloor[i]] == 0) {
				cache[nextFloor[i]] = cache[curFloor] + 1; // ������ ���Ե� ���� cache�� +1 (�׳� 1�� �����ص� ���� �ʳ�?)
				q.push(nextFloor[i]);
			}
		}
	}
	return -1; // ��ǥ ���� �������� ���ϸ�
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
// ���ѽð� 10:20