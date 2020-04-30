#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	string commend;
	queue<int> s;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> commend;
		if (commend == "push")
		{
			int temp;
			cin >> temp;
			s.push(temp);
			continue;
		}
		else if (commend == "pop")
		{
			if (s.empty())
			{
				cout << -1;
			}
			else
			{
				cout << s.front();
				s.pop();
			}
		}
		else if (commend == "size")
		{
			cout << s.size();
		}
		else if (commend == "empty")
		{
			cout << s.empty();
		}
		else if (commend == "front")
		{
			if (s.empty())
			{
				cout << -1;
			}
			else
				cout << s.front();
		}
		else if (commend == "back")
		{
			if (s.empty())
			{
				cout << -1;
			}
			else cout << s.back();
		}
		cout << "\n";
	}

}