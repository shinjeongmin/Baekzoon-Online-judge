#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int N, M;
	string tmpstr;
	cin >> tmpstr >> M;
	list<char> editor(tmpstr.begin(), tmpstr.end());
	auto cursor = editor.end(); //auto�� ���� ���� iterator ������ ���� �ʾƵ� ��

	// ������ ���� Ŀ���� �� ������
	for (int i = 0; i < M; i++)
	{
		char commend;
		cin >> commend;

		if (commend == 'L')
		{
			if(cursor != editor.begin())
				cursor--;
		}
		else if (commend == 'D')
		{
			if (cursor != editor.end())
				cursor++;
		}
		else if (commend == 'B')
		{
			// cursor�� ����Ű�� �ε������� -1�� �� ���� ����
			if (cursor != editor.begin())
			{
				cursor--;
				cursor = editor.erase(cursor);
			}
		}
		else if (commend == 'P')
		{
			char tempchr;
			cin >> tempchr;
			editor.insert(cursor,tempchr);
		}
	}

	for(auto i : editor)
		cout << i;
}