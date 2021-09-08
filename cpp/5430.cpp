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
	bool ERROR = false; // 에러일 경우
	bool Reverse = false; // 덱을 반대로 읽어야 하는가의 여부
	string p;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		deque<int> dq;
		// bool 변수( 상태 플래그역할) 초기화
		ERROR = false;
		Reverse = false;
		cin >> p >> n;

		//for (int j = 0; j < n; j++) 
			// 배열 입력 [1,2,3,4] 이런 형식으로 입력됨
		{
			string arr;
			string tempstr; // 임시 문자열
			cin >> arr; // [1,2,3,4] 형식의 string 입력

			for (int k = 0; k < arr.size(); k++)
			{ // 0번째 인덱스와 (마지막 - 1) 인덱스는 괄호이므로

				if (arr[k] == '[')
					continue;
				else if (arr[k] == ','||
					arr[k] == ']')
				{ // , ] 일 경우 배열에 string to int로 변환 후 숫자를 담음
					if (!tempstr.empty())
					{ // tempstr이 비어있지 않을 때만 넣음, 만약 비어있는데 stoi함수를 쓰면 에러뜸
						dq.push_back(stoi(tempstr));
						tempstr.clear();
					}
				}
				else if('0' <= arr[k] <= '9')
				{
					tempstr += arr[k];
				}
				else // 예외
				{
					cout << "Not correct input template";
				}
			}
		}

		for (int j = 0; j < p.size(); j++) 
			// 함수 수행
		{
			if (p[j] == 'R')
				// 덱 뒤집기
			{
				Reverse = !Reverse; // 뒤집기 상태 변환
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
					//뒤집기 상태에 따라 뒤에서 뺄지 앞에서 뺄지 결정
					if (Reverse)
					{ // 뒤집기 true이면 뒤에서(반대로) pop
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
			{ // 출력 [1,2] 형식
				if (Reverse) // Reverse가 true이면 뒤서부터 반대로 뺌
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
			cout << "]\n"; // 이거 하나 안넣어서 틀렸습니다 떴던거 실화임?
		}
	}
	return 0;
}