#include <iostream>
using namespace std;

void middle_press(int n, char c);
void Rawpress(int i, int a,int b);

int main() {
	int N;
	cin >> N;

	int num_side = 1 + (N - 1) * 4; // 한 변의 길이
	int Until_mid = (num_side + 1) / 2; // 중간까지 갈 때 대각선 칸 수

	int a, b; // a - 중간에 몇 개의 *(또는 공백)이 연속으로 들어가는가. b - 연속문양을 제외만 양쪽에 각각 몇개의 칸이 있고, 그 칸을 *과 공백이 돌아가며 채우는가.
	a = num_side, b = 0;

	int i;

	for (i = 0; a >= 1; i++) // 행의 갯수만큼 반복
	{
		Rawpress(i, a, b);

		cout << "\n";
		a -= 2; //중간에 들어가는 연속문양 "*" or " "은 2개씩 줄어듬
		b += 1;
	} // a=1일때까지 출력된 후 끝남.

	//중간 이후 후반부 
	a += 2, b -= 1; //a = 3에서 b는 Until_mid - 2에서 시작

	for (; a < num_side; i--) // 행의 갯수만큼 반복
	{
		a += 2; //중간에 들어가는 연속문양 "*" or " "은 2개씩 증가
		b -= 1;

		Rawpress(i, a, b);

		cout << "\n";
	} // a = num_side일때까지 출력된 후 끝남.
}

void middle_press(int n, char c) {
	for (int i = 0; i < n; i++) {
		cout << c;
	}
}

void Rawpress(int i,int a,int b)
{
	for (int j = 0; j < b; j++) //b로인해 연속문양 전에 생기는 *과 공백의 무늬
	{
		if (j % 2 == 0)
			cout << '*';
		else
			cout << ' ';
	}

	if (i % 2 == 0)
	{
		middle_press(a, '*');


		for (int j = 0; j < b; j++) //b로인해 연속문양 후에 생기는 *과 공백의 무늬
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

		for (int j = 0; j < b; j++) //b로인해 연속문양 후에 생기는 *과 공백의 무늬
		{
			if (j % 2 == 0)
				cout << '*';
			else
				cout << ' ';
		}
	}
}