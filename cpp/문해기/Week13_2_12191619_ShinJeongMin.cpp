#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int T, N, M;
int Messenger[500000 + 1]; // 메시지 전송자 번호를 저장하는 배열
int Answer[500000 + 1]; // 메시지를 읽지 않은 사람 수를 저장하는 배열

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M; // 채팅방 인원, 메시지 수
		for (int i = 1; i <= M; i++) {
			cin >> Messenger[i]; // 메시지 전송자 번호 입력
		}
		set<int> Readers; // 메시지를 읽은 사람들을 저장하는 딕셔너리
		for (int i = M; i >= 1; i--) { // M번 메시지부터 1번 메시지까지
			if (Readers.find(Messenger[i]) == Readers.end()) // find는 set에 없을 경우 end를 반환
				Readers.insert(Messenger[i]); // 없다면 딕셔너리에 전송자를 저장
			Answer[i] = N - Readers.size(); // 메시지를 읽지 않은 인원 = 전체 인원 - 읽은 인원
		}
		for (int i = 1; i <= M; i++) {
			cout << Answer[i] << "\n";
		}
	}
}

/*
3
10 12
2
1
3
4
2
1
4
7
8
7
2
1
5 3 
1
2
3
5 3
1
1
1
*/