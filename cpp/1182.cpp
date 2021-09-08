#include<iostream>
using namespace std;

int n, s, sum, cnt;
int arr[20];

void dfs(int i, int sum) {
	if (i == n) return; // ���� �ε����� ������ �� ������ ������ (�ε����� 0�����̹Ƿ� ������ �ʰ��� ��) return
	if (sum + arr[i] == s) cnt++; // ���� �ε��� �������� �κм����� ���� S�� ������ ī��Ʈ ����

	dfs(i + 1, sum); // ���� �ε����� ��ġ�� �ʰ� ���� �ε����� �Ѿ�� dfs
	dfs(i + 1, sum + arr[i]); // ���� �ε����� ���Ͽ� ���� �ε����� �Ѿ�� dfs
	/* 
	�� �� ����Լ��� ���ؼ� 
	���� �ε����� sum�� ���Ե� ��� / ���Ե��� ���� ���
	�� ���� ���� �̾����� ����Ʈ���� �����ȴ�.
	�� ����Ʈ������ depth�� �ִ��� ������ �̵����� �� 
	sum�� s�� ���� ��츦 ��󳻴� �������
	���� ���ϴ� �ڵ��̴�.
	*/
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cnt = 0;
	dfs(0, 0);

	cout << cnt << "\n";
}