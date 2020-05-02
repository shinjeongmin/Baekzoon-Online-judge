#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	vector<char> str;
	int N, M, cursor{ 0 };
	string tmpstr;
	cin >> tmpstr >> M;
	for(int i = 0; i < );
	str.push_back

	for (int i = 0; i < M; i++)
	{
		char commend;
		cin >> commend;
		cursor = str.size();
		// 시작할 때의 커서는 맨 오른쪽
		if (commend == 'L')
		{
			if(cursor > 0)
				cursor--;
		}
		else if (commend == 'D')
		{
			if (cursor < str.size())
				cursor++;
		}
		else if (commend == 'B')
		{
			if(cursor > 0)

		}
		else if(commend == 'P')
	}
}