#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void FailureFunction(string P);
bool KMPMatch(string T, string P);

int N, M;
string Puzzle[3000]; // ������
int F[3000]; // KMP �˰��� �����Լ�

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i <= N - 1; i++) {
		cin >> Puzzle[i];
	}

	string Text, Word; // �������� ��ģ ���ڿ�(�ؽ�Ʈ), �˻��� �ܾ�(����)
	for (int i = 0; i <= N - 1; i++) { // �������� ���η� ���� ���ڿ�
		Text += Puzzle[i];
		Text += "$";
	}
	for (int i = 0; i <= N - 1; i++) { // �������� ���η� ���� ���ڿ�
		for (int j = 0; j <= N - 1; j++) {
			Text += Puzzle[j][i];
		}
		Text += "$";
	}
	for (int i = 0; i <= N - 1; i++) { // �������� �밢��(�»�->���� �밢���� ���κ�)���� ���� ���ڿ�
		for (int j = 0; j <= N - i - 1; j++) {
			Text += Puzzle[j][i + j];
		}
		Text += "$";
	}
	for (int i = 1; i <= N - 1; i++) { // �������� �밢��(�»�->���� �밢���� �Ʒ��κ�)���� ���� ���ڿ�
		for (int j = 0; j <= N - i - 1; j++) {
			Text += Puzzle[i + j][j];
		}
		Text += "$";
	}

	for (int m = M; m > 0; m--) {
		cin >> Word; // �˻� �ܾ� �Է�
		FailureFunction(Word); // KMP �˰����� �����Լ� ���
		if (KMPMatch(Text, Word)) // �˻� ����
			cout << 1 << "\n";
		else // �˻� ����
			cout << 0 << "\n";
	}
}

void FailureFunction(string P) {
	F[0] = 0;
	int i = 1;
	int j = 0;
	while (i < P.size()) {
		if (P[i] == P[j]) { // �� ���ڰ� ��ġ�ϴ� ���
			F[i] = j + 1; // P[0..i]������ ��ġ�ϴ� ���λ�� �����̻��� �ִ� ����
			i++; // ���� �� ���ڸ� ���ϱ� ����
			j++;
		}
		else if (j > 0) // ������ �պκ��� ��ġ�ϴٰ� �߰��� ����ġ �ϴ� ���
			j = F[j - 1]; // ���� �Լ��� �̿��Ͽ� ����Ʈ
		else // ������ ù ��° ���ڿ��� ����ġ �ϴ� ���
		{
			F[i] = 0; // P[0]������ ��ġ�ϴ� ���λ�� �����̻��� �ִ� ���̴� 0
			i++; // ���̺� �˰���ó�� ������ ���������� �� ĭ ����Ʈ
		}
	}
}

bool KMPMatch(string T, string P) {
	int i = 0;
	int j = 0;
	while (i < T.size()) {
		if (T[i] == P[j]) // �� ���ڰ� ��ġ�ϴ� ���
		{
			if (j == P.size() - 1) // �˻��� ������ ���
				return true;
			i++; // ���� �� ���ڸ� ���ϱ� ����
			j++;
		}
		else if (j > 0) // ������ �պκ��� ��ġ�ϴٰ� �߰��� ����ġ �ϴ� ���
			j = F[j - 1]; // ���� �Լ��� �̿��Ͽ� ����Ʈ
		else // ������ ù ��° ���ڿ��� ����ġ�ϴ� ���
			i++; // ���̺� �˰���ó�� ������ ���������� �� ĭ ����Ʈ
	}
	return false; // �˻� ����
}

/*
7 12
APPLEJF
BIOIKIA
MATWGRE
RNAHEGP
COTPQYE
ZIOLLEH
CNINEXU
PIG
SOLVE
APPLE
HELLO
EGG
OPERA
COIN
PIANO
POTATO
HOPE
NINE
YEAR
*/

/*
6 2
ABCABA
AACABA
AABAAB
BCCAAC
ABBCAA
ACABBC
ABAAB
AAACA
*/