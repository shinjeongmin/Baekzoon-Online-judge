#include<iostream>
#include<algorithm>
using namespace std;

const int INF = 10000;
const int MAX = 101;

int N, M;
int graph[MAX][MAX];

//�÷��̵� �˰���;
void floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) //�ڱ� �ڽ����� ���� �� (loop)�� ���� (loop�� ����ִ� ���� 0)
					continue;
				// ���� i���� j�� ���� ����� k�� ���̿� ������
				else if (graph[i][k] && graph[k][j]) {
					if (graph[i][j] == 0) { // ó�� ���� �Ű����� ���̶�� (������ ���İ��� ����)
						graph[i][j] = graph[i][k] + graph[k][j]; // �߰������� ����ġ�� ������ ���� ����.
					}
					else { // �̹� ���� �ִ� ���̶�� �� ���� ���� ����
						graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = graph[b][a] = 1;
	}

	floyd();

	int Minresult = INF;
	int Minperson;
	for (int i = 1; i < N; i++) {
		int sum = 0;

		// �ش� �ε���(i)��° ����� �ɺ� ������ ���� ���ϱ�
		for (int j = 1; j <= N; j++) {
			sum += graph[i][j];
		}
		if (Minresult > sum) // �ּ� ������ �� ���� ���� �ε��� ����� �ɺ� ���������� ������
		{
			Minresult = sum;
			Minperson = i;
		}
	}

	cout << Minperson << "\n";
}