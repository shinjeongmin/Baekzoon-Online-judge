#include<iostream>	
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
#define endl '\n'

vector<string> madeWord;

int main() {
	string inputWrd;
	cin >> inputWrd;

	// 세 단어로 나누기 (각 string 인덱스를 활용)
	int w1 = 0, w2 = 1, w3 = 2;
	while (w2 < inputWrd.length() - 1) {
		// 세 단어에 구분된 인덱스까지의 문자 넣어서 분리
		string Wrd1, Wrd2, Wrd3;
		for (int i = 0; i < inputWrd.length(); i++) {
			if (i < w2) {
				Wrd1 += inputWrd[i];
			}
			else if (i < w3)
				Wrd2 += inputWrd[i];
			else
				Wrd3 += inputWrd[i];
		}
		// test
		/*cout << w1 << " " << w2 << " " << w3 << endl;
		cout << Wrd1 << " " << Wrd2 << " " << Wrd3 << endl;*/
		//

		// 세 단어 각각 뒤집기
		reverse(Wrd1.begin(), Wrd1.end());
		reverse(Wrd2.begin(), Wrd2.end());
		reverse(Wrd3.begin(), Wrd3.end());

		// 단어 합치기
		string assembleWrd = Wrd1 + Wrd2 + Wrd3;
		// test
		/*cout << assembleWrd << endl << endl;*/

		// 단어 push
		madeWord.push_back(assembleWrd);

		// w1,w2,w3 인덱스 업데이트
		if (w3 >= inputWrd.length() - 1) {
			w2++;
			w3 = w2 + 1;
		}
		else {
			w3++;
		}
		//
	}

	sort(madeWord.begin(), madeWord.end(), less<string>());
	cout << madeWord[0];
}
