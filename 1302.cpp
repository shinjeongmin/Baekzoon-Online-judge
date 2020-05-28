#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int N; // N <= 1000
	cin >> N;

	vector<string> BookTitleDup;
	vector<string> BookTitle;
	vector<string>::iterator BookTitle_iter;
	vector<int> BookNum;
	string temptitle; // <= 50
	int idx{0};

	// BookNum�� ó���Է��� ���� assign
	BookNum.assign(1, 0);

	// å �̸��� �Է�
	for (int i = 0; i < N; i++)
	{
		cin >> temptitle;
		BookTitleDup.push_back(temptitle);
	}

	// �������� ����
	sort(BookTitleDup.begin(), BookTitleDup.end(), less<string>());

	for (int i = 0; i < N; i++) {
		// �������
		temptitle = BookTitleDup[i];

		// å�̸��� �̺� Ž������ �� �̹� ������ �� å�� ī��Ʈ�� ����
		if (binary_search(BookTitle.begin(), BookTitle.end(), temptitle))
		{
			//find : �ش� å ������ ���� �ε��� �ּҸ� ���ͷ����Ϳ� ����
			BookTitle_iter = find(BookTitle.begin(), BookTitle.end(),
				temptitle);

			// �ش� å ���� �ε��� �ޱ�
			idx = distance(BookTitle.begin(), BookTitle_iter);

			BookNum[idx]++;
		}
		// ������ å�̸� �߰� �� ����
		else
		{
			// �߰�
			BookTitle.push_back(temptitle);
			BookNum.push_back(0);
		}
	}

	// ���� ���� �ȸ� å�� �ε����� ã��
	int max{ 0 };
	for (int i = 0; i < BookNum.size(); i++)
	{
		if (max < BookNum[i])
		{
			max = BookNum[i];
			idx = i;
		}
	}

	// ���
	cout << BookTitle[idx];
}