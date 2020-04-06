#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <utility>
using namespace std;

tuple<int, int, int, string> templog;
vector < tuple<int, int, int, string>> vec_log;
tuple<int, int, int> tempscore_result;
vector<tuple<int, int, int>> score_result;

vector<int> num_problem_try;
vector<pair<vector<int>, bool>> team_problem_Inf;
void scoring() 
{
	for (int i = 0; i < vec_log.size(); i++) {
		if (get<3>(vec_log[i]) == "WA" || // wrong answer
			get<3>(vec_log[i]) == "TLE" ||// Time-Limit Exceeded
			get<3>(vec_log[i]) == "RE") // run-time error
		{

		}
		else if (get<3>(vec_log[i]) == "AC") // Accepted
		{

		}
		else
		{
			cout << "ERROR" << endl;
			return;
		}
	}
}

int main() {
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
}