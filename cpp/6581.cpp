#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int sum{ 0 }; // �� �ٿ� �� ���ڰ� �ִ°�.
	bool sameLine = false; // ���� �ٿ� ����� ���ΰ�

	while (cin >> str) {

		if (str == "<br>")
		{
			cout << "\n";
			sum = 0;
		}
		else if (str == "<hr>")
		{
			if (!sum) // sum�� 0�̸�
			{
				for (int i = 0; i < 80; i++) cout << '-';
				cout << "\n";
			}
			else // sum�� 0�� �ƴҶ�
			{
				cout << "\n";
				for (int i = 0; i < 80; i++) cout << '-';
				cout << "\n";
				sum = 0;
			}
		}
		else
		{
			int len = str.length(); //���� ���� string�� ���̸� ����.
			/*if (!sum)
			{
				sum = len;
				cout << str;
				sameLine = true;
			}*/
			if (sum + len + 1 /*����*/ < 80) //80�̸�
			{
				if (!sum) // sum�� 0�ϰ�� ������ ���� �ʵ��� sameLine�� false��
				{
					sameLine = false;
				}

				if (sameLine) 
				{
					cout << " ";
					sum++;
				}

				cout << str;
				sum += len;

				if (sum == 80) // �ְ� ���� 80���ڿ� �� ���߸�
				{
					cout << "\n";
					sum = 0;
					sameLine = false;
				}
				else
					sameLine = true; //�����ٷ� �Ѿ�� �ʴ� �̻� ������ �߰�.
			}
			else // ���ڼ��� 80�̻��̸�
			{
				cout << "\n" << str;
				sum = len;
				sameLine = true;
			}

		}	
	}
}
