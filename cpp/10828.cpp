#include <iostream>
#include <stack>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	string commend;
	stack<int> s;
	int N;
	cin >> N;
	for(int i = 0; i < N;i ++)
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
				cout << s.top();
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
		else if (commend == "top")
		{
			if (s.empty())
			{
				cout << -1;
			}
			else
				cout << s.top();
		}
		cout << "\n";
	}

}