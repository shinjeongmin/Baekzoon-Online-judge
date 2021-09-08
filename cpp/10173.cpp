#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	bool found = false;
	while (str != "EOI")
	{
		getline(cin, str);

		if (str == "EOI") //EOI �Է� �� Ż��
			break;
		found = false;

 		string temp;

		for (int i = 0; i < str.size() && !found; i++) 
		{// string�� ã�� ���ĺ� �̿� ���ڸ� �߰��ϸ� ���� temp�� ����

			// ' ', ',', '.', '?'�� �������� temp�� ����Ǵ� ���� ��Ʈ
			if (str[i] == ' ' || str[i] == '.' 
				|| str[i] == ',' || str[i] == '?')
			{
				if (temp.size() >= 4) // Nemoö�� Ȯ�� �� 4���� �̻��ΰ� Ȯ��
				{
					if (temp[0] == 'n' || temp[0] == 'N' &&
						temp[1] == 'e' || temp[1] == 'E' &&
						temp[2] == 'm' || temp[2] == 'M' &&
						temp[3] == 'o' || temp[3] == 'O')
						// Nemo ö�� Ȯ��
					{
						// ö�� ��ġ�� found �� true
						found = true;
					}
					else
						temp = ""; //ö�ڰ� Ʋ����� temp �ʱ�ȭ
				}
				else 
				{
					temp = ""; // 4���� �̸��ΰ�� temp �ʱ�ȭ
				}
			}
			else
			{
				temp += str[i]; // ���ĺ��� ������ ��
			}
		}

		if (temp != "") // ������ �������� ���ĺ����� �����ٸ� temp�� ������� ����
		{
			// ������ ���� ���庸ȣ�� ���� �������� Ȯ��
			if (temp[0] == 'n' || temp[0] == 'N' &&
				temp[1] == 'e' || temp[1] == 'E' &&
				temp[2] == 'm' || temp[2] == 'M' &&
				temp[3] == 'o' || temp[3] == 'O')
			{
				found = true;
			}
			else
				temp = "";
		}

		cout << (found ? "Found" : "Missing") << "\n";
	}
}