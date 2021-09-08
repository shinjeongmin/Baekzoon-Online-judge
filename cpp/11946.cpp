#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <utility>
using namespace std;

tuple<int, int, int, string> templog; // 채점로그를 옮기는 임시벡터
vector < tuple<int, int, int, string>> vec_log; // 채점로그를 담는 벡터
tuple<int, int, int> tempscore_result; // 결과벡터에 튜플을 담는 용도인 임시벡터
vector<tuple<int, int, int>> score_result; // 결과(시간, 문제 수, 팀)를 담는 벡터

pair<vector<int>, vector<bool>> temp_team_problem_Inf; // 바로 밑의 벡터를 초기화하는 용도
vector<pair<vector<int>, vector<bool>>> team_problem_Inf; /* 팀별로 각각의
문제를 몇번 시도했는가를 담는 벡터, 풀었는지 여부가 담김 */

void scoring() 
{
	for (int i = 0; i < vec_log.size(); i++) {
		int team_number = get<1>(vec_log[i]); // 현재 채점하고 있는 로그의 팀 번호
		int problem_number = get<2>(vec_log[i]); // 현재 채점하고 있는 로그의 문제 번호

		if (team_problem_Inf[team_number].second[problem_number] == false &&
			(get<3>(vec_log[i]) == "WA" || // wrong answer
			get<3>(vec_log[i]) == "TLE" ||// Time-Limit Exceeded
			get<3>(vec_log[i]) == "RE")) // run-time error
		{
			team_problem_Inf[team_number].first[problem_number]++; // 해당 번호의 문제를 시도한 횟수 증가

		}
		else if (get<3>(vec_log[i]) == "AC" &&
			team_problem_Inf[team_number].second[problem_number] == false) // Accepted
		{
			team_problem_Inf[team_number].second[problem_number] = true; // 문제풀이 여부를 true로

			get<0>(score_result[team_number]) += get<0>(vec_log[i]) +
				20 * team_problem_Inf[team_number].first[problem_number]; // 패널티를 적용하여 결과벡터에 시간넣기

			get<1>(score_result[team_number])++; // 팀의 푼 문제수 +1
		}

	}
}

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
	if (get<1>(a) == get<1>(b))
	{
		if (get<0>(a) == get<0>(b))
			return get<2>(a) < get<2>(b);
		else
			return get<0>(a) < get<0>(b);
	}
	return get<1>(a) > get<1>(b);

	/*if (get<1>(a) != get<1>(b))
		return get<1>(a) > get<1>(b);
	else if (get<0>(a) != get<0>(b))
		return get<0>(a) < get<0>(b);
	else
		return get<2>(a) < get<2>(b);*/
}

void result_print(int num_of_team) {
	// 순위별로 정렬한 후 출력하기!!!
	stable_sort(&score_result[1], &score_result[1 + num_of_team], cmp);
	for (int i = 1; i <= num_of_team; i++) {
		// 팀, 문제 수, 시간 출력
		cout << get<2>(score_result[i]) << " "
			<< get<1>(score_result[i]) << " "
			<< get<0>(score_result[i]) << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 벡터 할당
	get<0>(tempscore_result) = 0;
	get<1>(tempscore_result) = 0;
	get<2>(tempscore_result) = 0;
	score_result.assign(101, tempscore_result); // 인덱스 0을 세지 않으므로
	temp_team_problem_Inf.first.assign(16, 0); // 인덱스 0을 세지 않으므로
	temp_team_problem_Inf.second.assign(16, false); // 인덱스 0을 세지 않으므로
	team_problem_Inf.assign(101, temp_team_problem_Inf); // 인덱스 0을 세지 않으므로

	int n, m, q;
	int time, teamnum, probnum;
	string result;

	cin >> n >> m >> q; // 팀, 문제, 채점로그

	for (int i = 0; i < q; i++) {
		cin >> time >> teamnum >> probnum >> result;

		get<0>(templog) = time;
		get<1>(templog) = teamnum;
		get<2>(templog) = probnum;
		get<3>(templog) = result;

		vec_log.push_back(templog);
	}

	// 팀 번호 순서대로 설정
	for (int i = 1; i <= n; i++) {
		get<2>(score_result[i]) = i;
	}

	scoring();
	result_print(n);
}

/*
4 3 13
10 1 1 AC
40 3 1 RE
60 2 1 WA
10 4 1 AC
10 4 2 AC
10 4 3 AC
10 2 1 AC
20 3 1 AC
60 3 2 AC
10 2 2 TLE
10 2 2 WA
10 2 2 TLE
10 2 2 AC
*/