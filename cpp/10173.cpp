#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	bool found = false;
	while (str != "EOI")
	{
		getline(cin, str);

		if (str == "EOI") //EOI 입력 시 탈출
			break;
		found = false;

 		string temp;

		for (int i = 0; i < str.size() && !found; i++) 
		{// string을 찾아 알파벳 이외 문자를 발견하면 끊어 temp에 저장

			// ' ', ',', '.', '?'를 기준으로 temp에 저장되는 문자 컷트
			if (str[i] == ' ' || str[i] == '.' 
				|| str[i] == ',' || str[i] == '?')
			{
				if (temp.size() >= 4) // Nemo철자 확인 전 4글자 이상인가 확인
				{
					if (temp[0] == 'n' || temp[0] == 'N' &&
						temp[1] == 'e' || temp[1] == 'E' &&
						temp[2] == 'm' || temp[2] == 'M' &&
						temp[3] == 'o' || temp[3] == 'O')
						// Nemo 철자 확인
					{
						// 철자 일치시 found 값 true
						found = true;
					}
					else
						temp = ""; //철자가 틀린경우 temp 초기화
				}
				else 
				{
					temp = ""; // 4글자 미만인경우 temp 초기화
				}
			}
			else
			{
				temp += str[i]; // 알파벳을 만났을 때
			}
		}

		if (temp != "") // 문장의 마지막이 알파벳으로 끝난다면 temp는 비어있지 않음
		{
			// 문장의 끝에 문장보호가 없이 끝날때를 확인
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