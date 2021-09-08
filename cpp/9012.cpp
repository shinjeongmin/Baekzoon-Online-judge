#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	string str;
	bool Correct{ true };
	stack<char> stk;
	for (int i = 0; i < N; i++) {
		Correct = true;
		while (!stk.empty())stk.pop();

		cin >> str;
		for (auto s : str){
			if (s == '(')
				// '('�� ���ÿ� ��
			{
				stk.push(s);
			}
			else if (s == ')' &&
				stk.empty())
				// ')'�� ���Դµ� '('�� ���� ������ ����� ���
			{
				Correct = false;
			}
			else if (s == ')' &&
				stk.top() == '(')
				// ')'�� ���ÿ� '('�� �ִ� ��� '('�� ¦�� �̷�� ������
			{
				stk.pop();
			}
			else
				cout << "Error NON CASE";
		}

		if (!stk.empty())
			// �Է��� �����µ� ���ÿ� '(' ���� �����ִ� ���
		{
			Correct = false;
		}

		cout << (Correct ? "YES" : "NO") << "\n";
	}
}