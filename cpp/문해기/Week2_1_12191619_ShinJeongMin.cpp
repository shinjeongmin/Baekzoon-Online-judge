#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int T, N, M, K, costAnswer;
string S;
string sentence[2000 + 1];
queue<string> word[20 + 1];

void init() {
	for (int i = 1; i < sizeof(sentence) / sizeof(sentence[0]); i++) {
		//cout << "string size : " << sizeof(sentence[i]) << " ";
		sentence[i].clear();
	}

	for (int i = 1; i < sizeof(word) / sizeof(word[0]); i++) {
		word[i] = queue<string>();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		init(); // �迭 �ʱ�ȭ
		cin >> N >> M;
		// ���� �Է�
		for (int i = 1; i <= M; i++) {
			cin >> sentence[i];
		}
		// �ܾ� �Է�
		for (int i = 1; i <= N; i++) {
			cin >> K;
			for (int j = 1; j <= K; j++) {
				cin >> S;
				word[i].push(S);
			}
		}

		for (int i = 1; i <= M; i++) {
			costAnswer = 0;
			for (int j = 1; j <= N; j++) {
				if (sentence[i] == word[j].front()) {
					word[j].pop();
					costAnswer = 1;
					break;
				}
			}
			if (costAnswer == 0)
				break;
		}
		cout << costAnswer << "\n";
	}
}

//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int T;
//	cin >> T;
//	for (int t = 0; t < T; t++) {
//		int N, M;
//		cin >> N >> M;
//		string stdWord[20][100];
//		int stdWordCnt[20];
//		string profSay[2000];
//
//		for (int i = 0; i < M; i++) {// ������ �ܾ�
//			cin >> profSay[i];
//		}
//		for (int i = 0; i < N; i++) { // �л� ���
//			int temp;
//			cin >> temp;
//			stdWordCnt[i] = temp;
//			for (int j = 0; j < temp; j++) { // �л��� �����
//				cin >> stdWord[i][j];
//			}
//		}
//
//		// ����1 : ù �ܾ ������� �� ��� ����
//		bool condition1 = false;
//		string firstWord = profSay[0];
//		for (int i = 0; i < N; i++) {
//			if (stdWord[i][0] == firstWord)
//				condition1 = true;
//		}
//
//		// ����2 : ��� �ܾ��� ���� 
//		bool condition2 = true;
//		int stdIdx[20][100] = { 0, };
//		int stdCurIdx[20] = { 0, };
//		for (int i = 0; i < M; i++) {
//			// �� �ܾ� ���� ���Կ��� Ȯ��
//			bool checkWordHave = false;
//			for (int j = 0; j < N; j++) {
//				if (stdWord[j][stdCurIdx[j]] == profSay[i]) // ���Ե� ���
//				{
//					checkWordHave = true;
//					stdIdx[j][stdCurIdx[j]] = i + 1; // �ε��� ��������
//					stdCurIdx[j]++;
//				}
//			}
//			if (checkWordHave == false)
//			{
//				condition2 = false;
//				break;
//			}
//		}
//
//		// ����3 : �ε��� �������� + ���� �ܾ�(0) �߰��� ����
//		bool condition3 = true;
//		for (int i = 0; i < N; i++) {
//			for (int j = 1; j < stdWordCnt[i]; j++) {
//				// 0�� ���ڵ� �߰��� ������ ����
//				if (stdIdx[i][j - 1] == 0 && stdIdx[i][j] != 0)
//				{
//					condition3 = false;
//				}
//			}
//		}
//
//		// ���� ������ ���
//		if (condition1 && condition2 && condition3)
//			cout << 1;
//		else
//		{
//			cout << 0;
//		}
//		cout << "\n";
//
//		continue;
//
//		//test ���
//		for (int i = 0; i < N; i++) {
//			cout << i << " ";
//			for (int j = 0; stdWord[i][j] != ""; j++) {
//				cout << stdWord[i][j] << " " << j << " ";
//			}
//			cout << "\n";
//			for (int j = 0; stdWord[i][j] != ""; j++) {
//				cout << stdIdx[i][j] << " ";
//			}
//			cout << "\n\n";
//		}
//	}
//}

/*
3
3 7
use binary search to solve the problem
4 use search solve study
3 binary the problem
4 to ordered array hard
3 6
ordered array to use binary search
4 use search solve study
3 binary the problem
4 to ordered array hard
3 6
ordered array to use binary search
5 to use search solve study
3 binary the problem
3 ordered array hard
*/