#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N, M;
		cin >> N >> M;
		string stdWord[20][100];
		int stdWordCnt[20];
		string profSay[2000];
		for (int i = 0; i < M; i++) {// ������ �ܾ�
			cin >> profSay[i];
		}
		for (int i = 0; i < N; i++) { // �л� ���
			int temp;
			cin >> temp;
			stdWordCnt[i] = temp;
			for (int j = 0; j < temp; j++) { // �л��� �����
				cin >> stdWord[i][j];
			}
		}

		// ����1 : ù �ܾ ������� �� ��� ����
		bool condition1 = false;
		string firstWord = profSay[0];
		for (int i = 0; i < N; i++) {
			if (stdWord[i][0] == firstWord)
				condition1 = true;
		}

		// ����2 : ��� �ܾ��� ���� 
		bool condition2 = true;
		int stdIdx[20][100] = { 0, };
		int stdCurIdx[20] = { 0, };
		for (int i = 0; i < M; i++) {
			// �� �ܾ� ���� ���Կ��� Ȯ��
			bool checkWordHave = false;
			for (int j = 0; j < N; j++) {
				if (stdWord[j][stdCurIdx[j]] == profSay[i]) // ���Ե� ���
				{
					checkWordHave = true;
					stdIdx[j][stdCurIdx[j]] = i + 1; // �ε��� ��������
					stdCurIdx[j]++;
				}
			}
			if (checkWordHave == false)
			{
				condition2 = false;
				break;
			}
		}

		// ����3 : �ε��� �������� + ���� �ܾ�(0) �߰��� ����
		bool condition3 = true;
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < stdWordCnt[i]; j++) {
				// 0�� ���ڵ� �߰��� ������ ����
				if (stdIdx[i][j - 1] == 0 && stdIdx[i][j] != 0)
				{
					condition3 = false;
				}
			}
		}

		// ���� ������ ���
		if (condition1 && condition2 && condition3)
			cout << 1;
		else
		{
			cout << 0;
		}
		cout << "\n";

		continue;

		//test ���
		for (int i = 0; i < N; i++) {
			cout << i << " ";
			for (int j = 0; stdWord[i][j] != ""; j++) {
				cout << stdWord[i][j] << " " << j << " ";
			}
			cout << "\n";
			for (int j = 0; stdWord[i][j] != ""; j++) {
				cout << stdIdx[i][j] << " ";
			}
			cout << "\n\n";
		}
	}
}