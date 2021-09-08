#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct str { 
	int line; // ���� ��, ������ �� (��)
	int current_idx; // ���� �ε��� (ĭ)
	int start_idx; // �������� �ε���
	str(int line, int current_idx, int start_idx) // str ����ü ������
		: line(line), current_idx(current_idx), start_idx(start_idx) {

	}
};

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	char c;
	vector<vector<int>> vec(2, vector<int>(N + 1, 0)); // ������ ����� ĭ�� ������ ĭ���� ����
	vector<vector<int>> visit(2, vector<int>(N + 1, 0)); // �� ����� ĭ�� �湮�ߴ��� ���� ����

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> c; // 1101�� ���������� ������ ���� ������ ���ڷ� �޾ƾ� �ϹǷ� char ���
			vec[i][j] = (int)c - 48; // �ƽ�Ű �ڵ� ����
		}
	}

	int ans = 0; // ���ɿ��� ���
	queue<str> q; // ����ü�� �̷���� ť
	q.push(str(0, 1, 1));

	while (!q.empty()) {
		int line = q.front().line; // 0:���� ��, 1:������ ��
		int current_idx = q.front().current_idx; // ���� index
		int start_idx = q.front().start_idx; // �������� index
		q.pop();

		if (current_idx > N) { // ���� �ε����� N�� �Ѿ�� ������.
			ans = 1;
			break;
		}

		//�̹� Ȯ���ߴ��� üũ
		if (visit[line][current_idx])
			continue;

		visit[line][current_idx] = 1; // �湮���θ� üũ��

		// 1. ��ĭ ������ �̵�
		// ���� �ε��� +1�� N�� �Ѱų� �Ǵ� �̵��� ���� �ε����� ������ ĭ�� ���
		if (current_idx + 1 > N || vec[line][current_idx + 1] == 1) {
			// ����ĭ�� ť�� �����ϰ� ���������� +1�ؼ� ���� �� ĭ�� �� ĭ ����
			q.push(str(line, current_idx + 1, start_idx + 1)); 
		}

		// 2. ��ĭ �ڷ� �̵�
		// �ٷ� ��ĭ�� ����� ĭ�� �����ε������� 1�̻� ũ��, ������ ĭ�� ���
		if (current_idx - 1 >= start_idx + 1 &&
			vec[line][current_idx - 1] == 1) {
			// �� ĭ�� ť�� �����ϰ� ���������� +1�ؼ� ���� �� ĭ�� ����
			q.push(str(line, current_idx -1, start_idx + 1));
		}

		// 3.�ݴ��� �ٷ� ����
		// ���� 0�̸� 1, 1�̸� 0 ���� �� �̵�
		line = (line == 0) ? 1 : 0;
		// +Kĭ�� N�� �Ѱų�, Kĭ �̵��ϴ� ĭ�� ������ ĭ�� ���
		if (current_idx + K > N || vec[line][current_idx + K] == 1) {
			// +Kĭ�� ť�� �����ϰ� ���������� +1�ؼ� ���� �� ĭ ����
			q.push(str(line, current_idx + K, start_idx + 1));
		}
	}

	cout << ans << endl;
	return 0;
}
//���ѽð� 3:30