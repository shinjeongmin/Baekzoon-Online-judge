#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	int isJava = 2;
	bool isBoth = true;
	string name;

	cin >> name;

	for (int i = 0; i < name.length(); i++) {
		if (name[i] == '_' && name[i + 1] != '_' && islower(name[i + 1])) //_ C++����
		{
			if (isJava == 1)
			{
				isJava = 2;
				break;
			}
			isJava = false;
			isBoth = false;
		}
		else if (islower(name[i]) && isupper(name[i + 1])) // �빮�� Java����
		{
			if (isJava == 0)
			{
				isJava = 2;
				break;
			}
			isJava = true;
			isBoth = false;
		}
		else if (name[i] == '_' && name[i + 1] == '_' || //_�� ����
			name[0] == '_' || // _�� ó��
			name[name.length()-1] == '_' ||  //_�� ������
			isupper(name[0]) ||  // �빮�ڰ� ó��
			name[i] == '_' && isupper(name[i+1])// _������ �빮��
			)
		{
			isJava = 2;
			isBoth = false;
			break;
		}
	}

	if (isBoth)
		cout << name;
	else {
		switch (isJava) {
		case true: //Java�� ���
			for (int i = 0; i < name.length(); i++) {
				if (isupper(name[i]))
				{
					cout << '_';
					cout << static_cast<char>(tolower(name[i]));
				}
				else
					cout << name[i];
			}
			break;
		case false: //C++�� ���
			for (int i = 0; i < name.length(); i++) {
				if (name[i] == '_')
				{
					name[i + 1] = toupper(name[i + 1]);
				}
				else
					cout << name[i];
			}
			break;
		default:
			cout << "Error!";
			break;

		}
	}
}