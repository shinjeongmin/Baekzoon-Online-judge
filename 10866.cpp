#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	string commend;
	deque<int> dq;

	for (int i = 0; i < N; i++)
	{
		cin >> commend;

		if (commend == "push_front")
		{
			int temp;
			cin >> temp;
			dq.push_front(temp);
		}
		else if (commend == "push_back")
		{
			int temp;
			cin >> temp;
			dq.push_back(temp);
		}
		else if (commend == "pop_front")
		{
			if (dq.empty())
			{
				cout << -1;
			}
			else
			{
				cout << dq.front();
				dq.pop_front();
			}
			cout << "\n";
		}
		else if (commend == "pop_back")
		{
			if (dq.empty())
			{
				cout << -1;
			}
			else
			{
				cout << dq.back();
				dq.pop_back();
			}
			cout << "\n";
		}
		else if (commend == "size")
		{
			cout << dq.size();
			cout << "\n";
		}
		else if (commend == "empty")
		{
			cout << dq.empty();
			cout << "\n";
		}
		else if (commend == "front")
		{
			if (dq.empty())
			{
				cout << -1;
			}
			else
			{
				cout << dq.front();
			}
			cout << "\n";
		}
		else if (commend == "back")
		{
			if (dq.empty())
			{
				cout << -1;
			}
			else
			{
				cout << dq.back();
			}
			cout << "\n";
		}
	}
}