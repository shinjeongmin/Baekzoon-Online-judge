#include <iostream>
using namespace std;

int main() {
	int A, B, C, X, Y;
	int totalPride{ 0 }, remainingChick, chickSameQuantity;
	bool isXmore; //���ġŲ�� ���� �� ������?

	cin >> A >> B >> C >> X >> Y;
	chickSameQuantity = (X >= Y ? Y : X); //���� �Ķ��̵尡 �Ѵ� �ʿ��� �ּҼ���
	remainingChick = X + Y - 2 * chickSameQuantity; //�Ѵ� �ʿ��� �ּҼ����� �� ������
	isXmore = (X >= Y ? true : false);

	if (A + B >= 2 * C) { //���� ���1 + �Ķ��̵�1 >= �ݹ�2 �̸� �ݹ����� ��°� ��.
		totalPride += C * 2 * chickSameQuantity;
		
		//�߰������� �ּ� X,Y���� �̹Ƿ� �������� �ʰ��������.
		//�ݹ� 2�� ������ �Ѹ��� ���ݺ��� �θ� �ݹ����� 2����°� �� �ΰ� ���Ű���.
		if ((isXmore && A >= 2 * C) || (!isXmore && B >= 2 * C)) //��� or fried �Ѹ������ݺ��� �ݹ�2������ �ΰų� ������
		{
			totalPride += 2 * C * remainingChick;
		}
		else 
		totalPride += (isXmore ? A * remainingChick : B * remainingChick);
	}
	else {
		totalPride += X * A + Y * B;
	}

	cout << totalPride;
}