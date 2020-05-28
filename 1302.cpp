#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int N; // N <= 1000
	cin >> N;

	vector<string> BookTitleDup;
	vector<string> BookTitle;
	vector<string>::iterator BookTitle_iter;
	vector<int> BookNum;
	string temptitle; // <= 50
	int idx{0};

	// BookNum는 처음입력할 때는 assign
	BookNum.assign(1, 0);

	// 책 이름들 입력
	for (int i = 0; i < N; i++)
	{
		cin >> temptitle;
		BookTitleDup.push_back(temptitle);
	}

	// 오름차순 정렬
	sort(BookTitleDup.begin(), BookTitleDup.end(), less<string>());

	for (int i = 0; i < N; i++) {
		// 순서대로
		temptitle = BookTitleDup[i];

		// 책이름을 이분 탐색했을 때 이미 있으면 그 책의 카운트를 증가
		if (binary_search(BookTitle.begin(), BookTitle.end(), temptitle))
		{
			//find : 해당 책 제목을 가진 인덱스 주소를 이터레이터에 저장
			BookTitle_iter = find(BookTitle.begin(), BookTitle.end(),
				temptitle);

			// 해당 책 제목 인덱스 받기
			idx = distance(BookTitle.begin(), BookTitle_iter);

			BookNum[idx]++;
		}
		// 없으면 책이름 추가 후 정렬
		else
		{
			// 추가
			BookTitle.push_back(temptitle);
			BookNum.push_back(0);
		}
	}

	// 가장 많이 팔린 책의 인덱스를 찾음
	int max{ 0 };
	for (int i = 0; i < BookNum.size(); i++)
	{
		if (max < BookNum[i])
		{
			max = BookNum[i];
			idx = i;
		}
	}

	// 출력
	cout << BookTitle[idx];
}