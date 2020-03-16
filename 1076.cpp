#include <iostream>	
#include <math.h>
using namespace std;

int main() {
	string kindOfResist[] = { "black", "brown", "red", "orange", "yellow", "green"
	, "blue", "violet", "grey", "white" }; // 각 저항의 색들을 순서대로 담은 string 배열
	string resist[3]; //세개의 색을 받을 string 배열
	long long valueOfResist = 0; //최종 저항값

	cin >> resist[0] >> resist[1] >> resist[2];

	for (int j = 0; j < 3; j++) { // 세개의 색을 받으므로 세번 처리
		for (int i = 0; i < sizeof(kindOfResist) / sizeof(string); i++) {
			// sizeof(kindOfResist) / sizeof(string)은 kindOfResist에 담긴 string 문자열의 갯수이다.
			if (!resist[j].compare(kindOfResist[i])) //j번째 저항의 색이 어떤 문자열과 일치하는 지 10개를 비교한다.
			{
				switch (j) {
				case 0: //첫번째 색을 추가
					valueOfResist += i;
					break;
				case 1: // 두번째 색은 첫번째 색의 번호를 10의 자리로 옮긴 후 추가.
					valueOfResist *= 10;
					valueOfResist += i;
					break;
				case 2: //마지막 색은 현재 두 자리 수에 10^(색의 번호) 만큼 곱한다.
					valueOfResist *= pow(10, i);
					break;
				}
			}
		}
	}

	cout << valueOfResist;
}