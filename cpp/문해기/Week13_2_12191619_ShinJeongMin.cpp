#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int T, N, M;
int Messenger[500000 + 1]; // �޽��� ������ ��ȣ�� �����ϴ� �迭
int Answer[500000 + 1]; // �޽����� ���� ���� ��� ���� �����ϴ� �迭

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M; // ä�ù� �ο�, �޽��� ��
		for (int i = 1; i <= M; i++) {
			cin >> Messenger[i]; // �޽��� ������ ��ȣ �Է�
		}
		set<int> Readers; // �޽����� ���� ������� �����ϴ� ��ųʸ�
		for (int i = M; i >= 1; i--) { // M�� �޽������� 1�� �޽�������
			if (Readers.find(Messenger[i]) == Readers.end()) // find�� set�� ���� ��� end�� ��ȯ
				Readers.insert(Messenger[i]); // ���ٸ� ��ųʸ��� �����ڸ� ����
			Answer[i] = N - Readers.size(); // �޽����� ���� ���� �ο� = ��ü �ο� - ���� �ο�
		}
		for (int i = 1; i <= M; i++) {
			cout << Answer[i] << "\n";
		}
	}
}

/*
3
10 12
2
1
3
4
2
1
4
7
8
7
2
1
5 3 
1
2
3
5 3
1
1
1
*/