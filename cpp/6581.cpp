#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int sum{ 0 }; // 한 줄에 몇 글자가 있는가.
	bool sameLine = false; // 같은 줄에 출력할 것인가

	while (cin >> str) {

		if (str == "<br>")
		{
			cout << "\n";
			sum = 0;
		}
		else if (str == "<hr>")
		{
			if (!sum) // sum이 0이면
			{
				for (int i = 0; i < 80; i++) cout << '-';
				cout << "\n";
			}
			else // sum이 0이 아닐때
			{
				cout << "\n";
				for (int i = 0; i < 80; i++) cout << '-';
				cout << "\n";
				sum = 0;
			}
		}
		else
		{
			int len = str.length(); //현재 받은 string의 길이를 저장.
			/*if (!sum)
			{
				sum = len;
				cout << str;
				sameLine = true;
			}*/
			if (sum + len + 1 /*공백*/ < 80) //80미만
			{
				if (!sum) // sum이 0일경우 공백을 넣지 않도록 sameLine을 false로
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

				if (sum == 80) // 넣고 나서 80글자에 딱 맞추면
				{
					cout << "\n";
					sum = 0;
					sameLine = false;
				}
				else
					sameLine = true; //다음줄로 넘어가지 않는 이상 공백을 추가.
			}
			else // 글자수가 80이상이면
			{
				cout << "\n" << str;
				sum = len;
				sameLine = true;
			}

		}	
	}
}
