#include <iostream>
using namespace std;

void middle_press(int n, char c);
void Rawpress(int i, int a,int b);

int main() {
	int N;
	cin >> N;

	int num_side = 1 + (N - 1) * 4; // �� ���� ����
	int Until_mid = (num_side + 1) / 2; // �߰����� �� �� �밢�� ĭ ��

	int a, b; // a - �߰��� �� ���� *(�Ǵ� ����)�� �������� ���°�. b - ���ӹ����� ���ܸ� ���ʿ� ���� ��� ĭ�� �ְ�, �� ĭ�� *�� ������ ���ư��� ä��°�.
	a = num_side, b = 0;

	int i;

	for (i = 0; a >= 1; i++) // ���� ������ŭ �ݺ�
	{
		Rawpress(i, a, b);

		cout << "\n";
		a -= 2; //�߰��� ���� ���ӹ��� "*" or " "�� 2���� �پ��
		b += 1;
	} // a=1�϶����� ��µ� �� ����.

	//�߰� ���� �Ĺݺ� 
	a += 2, b -= 1; //a = 3���� b�� Until_mid - 2���� ����

	for (; a < num_side; i--) // ���� ������ŭ �ݺ�
	{
		a += 2; //�߰��� ���� ���ӹ��� "*" or " "�� 2���� ����
		b -= 1;

		Rawpress(i, a, b);

		cout << "\n";
	} // a = num_side�϶����� ��µ� �� ����.
}

void middle_press(int n, char c) {
	for (int i = 0; i < n; i++) {
		cout << c;
	}
}

void Rawpress(int i,int a,int b)
{
	for (int j = 0; j < b; j++) //b������ ���ӹ��� ���� ����� *�� ������ ����
	{
		if (j % 2 == 0)
			cout << '*';
		else
			cout << ' ';
	}

	if (i % 2 == 0)
	{
		middle_press(a, '*');


		for (int j = 0; j < b; j++) //b������ ���ӹ��� �Ŀ� ����� *�� ������ ����
		{
			if (j % 2 != 0)
				cout << '*';
			else
				cout << ' ';
		}
	}
	else
	{
		middle_press(a, ' ');

		for (int j = 0; j < b; j++) //b������ ���ӹ��� �Ŀ� ����� *�� ������ ����
		{
			if (j % 2 == 0)
				cout << '*';
			else
				cout << ' ';
		}
	}
}