#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <utility>
using namespace std;

tuple<int, int, int, string> templog; // ä���α׸� �ű�� �ӽú���
vector < tuple<int, int, int, string>> vec_log; // ä���α׸� ��� ����
tuple<int, int, int> tempscore_result; // ������Ϳ� Ʃ���� ��� �뵵�� �ӽú���
vector<tuple<int, int, int>> score_result; // ���(�ð�, ���� ��, ��)�� ��� ����

pair<vector<int>, vector<bool>> temp_team_problem_Inf; // �ٷ� ���� ���͸� �ʱ�ȭ�ϴ� �뵵
vector<pair<vector<int>, vector<bool>>> team_problem_Inf; /* ������ ������
������ ��� �õ��ߴ°��� ��� ����, Ǯ������ ���ΰ� ��� */

void scoring() 
{
	for (int i = 0; i < vec_log.size(); i++) {
		int team_number = get<1>(vec_log[i]); // ���� ä���ϰ� �ִ� �α��� �� ��ȣ
		int problem_number = get<2>(vec_log[i]); // ���� ä���ϰ� �ִ� �α��� ���� ��ȣ

		if (team_problem_Inf[team_number].second[problem_number] == false &&
			(get<3>(vec_log[i]) == "WA" || // wrong answer
			get<3>(vec_log[i]) == "TLE" ||// Time-Limit Exceeded
			get<3>(vec_log[i]) == "RE")) // run-time error
		{
			team_problem_Inf[team_number].first[problem_number]++; // �ش� ��ȣ�� ������ �õ��� Ƚ�� ����

		}
		else if (get<3>(vec_log[i]) == "AC" &&
			team_problem_Inf[team_number].second[problem_number] == false) // Accepted
		{
			team_problem_Inf[team_number].second[problem_number] = true; // ����Ǯ�� ���θ� true��

			get<0>(score_result[team_number]) += get<0>(vec_log[i]) +
				20 * team_problem_Inf[team_number].first[problem_number]; // �г�Ƽ�� �����Ͽ� ������Ϳ� �ð��ֱ�

			get<1>(score_result[team_number])++; // ���� Ǭ ������ +1
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
	// �������� ������ �� ����ϱ�!!!
	stable_sort(&score_result[1], &score_result[1 + num_of_team], cmp);
	for (int i = 1; i <= num_of_team; i++) {
		// ��, ���� ��, �ð� ���
		cout << get<2>(score_result[i]) << " "
			<< get<1>(score_result[i]) << " "
			<< get<0>(score_result[i]) << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// ���� �Ҵ�
	get<0>(tempscore_result) = 0;
	get<1>(tempscore_result) = 0;
	get<2>(tempscore_result) = 0;
	score_result.assign(101, tempscore_result); // �ε��� 0�� ���� �����Ƿ�
	temp_team_problem_Inf.first.assign(16, 0); // �ε��� 0�� ���� �����Ƿ�
	temp_team_problem_Inf.second.assign(16, false); // �ε��� 0�� ���� �����Ƿ�
	team_problem_Inf.assign(101, temp_team_problem_Inf); // �ε��� 0�� ���� �����Ƿ�

	int n, m, q;
	int time, teamnum, probnum;
	string result;

	cin >> n >> m >> q; // ��, ����, ä���α�

	for (int i = 0; i < q; i++) {
		cin >> time >> teamnum >> probnum >> result;

		get<0>(templog) = time;
		get<1>(templog) = teamnum;
		get<2>(templog) = probnum;
		get<3>(templog) = result;

		vec_log.push_back(templog);
	}

	// �� ��ȣ ������� ����
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