#include<iostream>
#include<vector>
#include<queue>
using namespace std;

queue<int> computer[100 + 1];
bool check[100 + 1];
int InfectedComputers;

void warmInfect(int n) {
	check[n] = true;

	// ť�� ������� ������ Ž��
	if (!check[computer[n].front()]) { //Ž������ �ʾ�����
		warmInfect(computer[n].front());
		computer[n].pop();
		InfectedComputers++;
	}
	else { //Ž���ߴٸ� �׳� ������
		computer[n].pop();
	}

	// ť�� �� ������ ���
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

		// ���� ��带 ���� �����ش�.
		computer[com1].push(com2);
		computer[com2].push(com1);
	}

	for (int i = 1; i <= 1; i++) {
		warmInfect(i);
	}

	cout << InfectedComputers;
}