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
		// �ҹ���
		if ('a' <= s[i] && s[i] <= 'z')
		{
			// ù��° ���ڰ� �ƴҶ� 
			if (i != 0)
			{
				if (s[i - 1] == s[i])
				{
					// �Ȼ�
				}
				else
					arr[s[i] - 'a']--;
			}
			// ù��° ����
			else
				arr[s[i] - 'a']--;
		}
		// �빮��
		else if ('A' <= s[i] && s[i] <= 'Z')
		{
			// ù��° ���ڰ� �ƴҶ� 
			if (i != 0)
			{
				if (s[i - 1] == s[i])
				{
					// �Ȼ�
				}
				else
					arr[s[i] - 'A']--;
			}
			// ù��° ����
			else
				arr[s[i] - 'A']--;
		}
		// ����
		else if (s[i] == ' ')
		{
			if (s[i - 1] == s[i])
			{
				// �Ȼ�
			}
			else
				space--;
		}

		// ����
		if (i == 0)
		{
			// �ҹ���
			if ('a' <= s[i] && s[i] <= 'z')
			{
				arr[s[i] - 'a']--;
			}
			// �빮��
			else if ('A' <= s[i] && s[i] <= 'Z')
			{
				arr[s[i] - 'A']--;
			}
			title += toupper(s[i]);
		}
		else if (i > 0)
		{
			// �տ� �����ְ� ���� �ε����� ������ �ƴϸ� ����
			if (s[i - 1] == ' ' && s[i] != ' ') {
				// �ҹ���
				if ('a' <= s[i] && s[i] <= 'z')
				{
					arr[s[i] - 'a']--;
				}
				// �빮��
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