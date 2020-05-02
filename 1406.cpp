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
	auto cursor = editor.end(); //auto를 쓰면 굳이 iterator 선언을 하지 않아도 되

	// 시작할 때의 커서는 맨 오른쪽
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
			// cursor가 가리키는 인덱스에서 -1을 뺀 값을 삭제
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