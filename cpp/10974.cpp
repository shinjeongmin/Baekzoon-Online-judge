#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string>
using namespace std;
vector<string> Result;

void Permutation(vector<int> &Array,int Start,int End) 
{
	if (Start == End)
	{
		string temp;
		for (auto it : Array)
		{
			temp += to_string(it) + " ";
		}
		Result.push_back(temp);
	}
	else 
	{
		for (int i = Start; i <= End; i++) 
		{
			swap(Array[Start - 1], Array[i - 1]);
			Permutation(Array, Start + 1, End);
			swap(Array[Start - 1], Array[i - 1]); // 스왑한 배열 돌려놓기
		}
	}

}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> Array;
	for (int i = 0; i < N; i++)
	{
		Array.push_back(i + 1);
	}

	Permutation(Array, *Array.begin(), *(Array.end() - 1));

	sort(Result.begin(), Result.end());

	for (auto i : Result) {
		cout << i << "\n";
	}
}