#include<iostream>
#include<string>
using namespace std;

int main() {
	string s, title;
	int space;
	getline(cin, s);
	cin >> space;

	int arr[26];

	for (int i = 0; i < 26; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < s.length(); i++){
		// 소문자
		if ('a' <= s[i] && s[i] <= 'z')
		{
			// 첫번째 문자가 아닐때 
			if (i != 0)
			{
				if (s[i - 1] == s[i])
				{
					// 안빼
				}
				else
					arr[s[i] - 'a']--;
			}
			// 첫번째 문자
			else
				arr[s[i] - 'a']--;
		}
		// 대문자
		else if ('A' <= s[i] && s[i] <= 'Z')
		{
			// 첫번째 문자가 아닐때 
			if (i != 0)
			{
				if (s[i - 1] == s[i])
				{
					// 안빼
				}
				else
					arr[s[i] - 'A']--;
			}
			// 첫번째 문자
			else
				arr[s[i] - 'A']--;
		}
		// 공백
		else if (s[i] == ' ')
		{
			if (s[i - 1] == s[i])
			{
				// 안빼
			}
			else
				space--;
		}

		// 제목
		if (i == 0)
		{
			// 소문자
			if ('a' <= s[i] && s[i] <= 'z')
			{
				arr[s[i] - 'a']--;
			}
			// 대문자
			else if ('A' <= s[i] && s[i] <= 'Z')
			{
				arr[s[i] - 'A']--;
			}
			title += toupper(s[i]);
		}
		else if (i > 0)
		{
			// 앞에 공백있고 현재 인덱스는 공백이 아니면 제목
			if (s[i - 1] == ' ' && s[i] != ' ') {
				// 소문자
				if ('a' <= s[i] && s[i] <= 'z')
				{
					arr[s[i] - 'a']--;
				}
				// 대문자
				else if ('A' <= s[i] && s[i] <= 'Z')
				{
					arr[s[i] - 'A']--;
				}
				title += toupper(s[i]);
			}
		}
	}

	if (space < 0)
	{
		cout << -1;
		return 0;
	}
	for (auto i : arr) {
		if (i < 0) {
			cout << -1;
			return 0;
		}
	}
	cout << title;
}

/*
show me the money
4
1 0 3 2 1 0 0 2 0 0 0 0 4 1 2 0 0 0 1 2 0 0 1 0 1 0
a b c d e f g h i j k l m n o p q r s t u v w x y z

There is no cow levelllllllllllllllllllllelelelelelel
5
1 0 2 0 4 3 0 1 2 0 0 3 0 2 2 0 4 1 1 2 0 1 1 0 0 0
a b c d e f g h i j k l m n o p q r s t u v w x y z
*/