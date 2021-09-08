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
				// '('는 스택에 들어감
			{
				stk.push(s);
			}
			else if (s == ')' &&
				stk.empty())
				// ')'이 들어왔는데 '('가 없이 스택이 비었을 경우
			{
				Correct = false;
			}
			else if (s == ')' &&
				stk.top() == '(')
				// ')'는 스택에 '('이 있는 경우 '('과 짝을 이루어 삭제함
			{
				stk.pop();
			}
			else
				cout << "Error NON CASE";
		}

		if (!stk.empty())
			// 입력이 끝났는데 스택에 '(' 값이 남아있는 경우
		{
			Correct = false;
		}

		cout << (Correct ? "YES" : "NO") << "\n";
	}
}