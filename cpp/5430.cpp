#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <deque>
#include <stdlib.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int T,n;
	bool ERROR = false; // ������ ���
	bool Reverse = false; // ���� �ݴ�� �о�� �ϴ°��� ����
	string p;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		deque<int> dq;
		// bool ����( ���� �÷��׿���) �ʱ�ȭ
		ERROR = false;
		Reverse = false;
		cin >> p >> n;

		//for (int j = 0; j < n; j++) 
			// �迭 �Է� [1,2,3,4] �̷� �������� �Էµ�
		{
			string arr;
			string tempstr; // �ӽ� ���ڿ�
			cin >> arr; // [1,2,3,4] ������ string �Է�

			for (int k = 0; k < arr.size(); k++)
			{ // 0��° �ε����� (������ - 1) �ε����� ��ȣ�̹Ƿ�

				if (arr[k] == '[')
					continue;
				else if (arr[k] == ','||
					arr[k] == ']')
				{ // , ] �� ��� �迭�� string to int�� ��ȯ �� ���ڸ� ����
					if (!tempstr.empty())
					{ // tempstr�� ������� ���� ���� ����, ���� ����ִµ� stoi�Լ��� ���� ������
						dq.push_back(stoi(tempstr));
						tempstr.clear();
					}
				}
				else if('0' <= arr[k] <= '9')
				{
					tempstr += arr[k];
				}
				else // ����
				{
					cout << "Not correct input template";
				}
			}
		}

		for (int j = 0; j < p.size(); j++) 
			// �Լ� ����
		{
			if (p[j] == 'R')
				// �� ������
			{
				Reverse = !Reverse; // ������ ���� ��ȯ
			}
			else if (p[j] == 'D')
			{
				if (dq.empty())
				{
					cout << "error" << "\n";
					ERROR = true;
					break;
				}
				else
				{
					//������ ���¿� ���� �ڿ��� ���� �տ��� ���� ����
					if (Reverse)
					{ // ������ true�̸� �ڿ���(�ݴ��) pop
						dq.pop_back();
					}
					else
					{
						dq.pop_front();
					}
				}
			}
			else
				cout << "Not Function of AC";
		}
		
		if (!ERROR)
		{
			cout << "[";
			while (!dq.empty())
			{ // ��� [1,2] ����
				if (Reverse) // Reverse�� true�̸� �ڼ����� �ݴ�� ��
				{
					cout << dq.back();
					dq.pop_back();
				}
				else
				{
					cout << dq.front();
					dq.pop_front();
				}
				if (!dq.empty())
					cout << ",";
			}
			cout << "]\n"; // �̰� �ϳ� �ȳ־ Ʋ�Ƚ��ϴ� ������ ��ȭ��?
		}
	}
	return 0;
}