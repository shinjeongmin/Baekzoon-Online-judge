#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

// atoi , atoll�� Ǯ�� �����ʰ��� ������.. �Ѥ�

string DeleteZero(string str) {
	bool firstZero = true;
	string reStr = "";
	for (int i = 0; i < str.length(); i++) {
		if (!firstZero || str[i] != '0') {
			reStr += str[i];
			firstZero = false;
		}
	}
	if (reStr == "")
		return "0";

	return reStr;
}

bool comp(string a, string b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	else {
		return a < b;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<string> result;
	vector<string> result_num;
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;

		string temp = "";
		for (int j = 0; j < input.length(); j++) {

			// �����̸� ����
			if ('0' <= input[j] && input[j] <= '9') {
				temp += input[j];
			}
			// �ƴϸ� ���Ϳ� ���� �߰�
			else {
				// temp�� ��������� ���� ����.
				if (temp != ""){
					result.push_back(temp);
					temp = "";
				}
			}
		}
		// ������ �ε����� �����̸� temp�� push.
		if ('0' <= input[input.length() - 1] && input[input.length() - 1] <= '9') {
			result.push_back(temp);
		}
	}

	// ������ ���ڿ����� ������ ����
	for (int i = 0; i < result.size(); i++) {
		result_num.push_back(DeleteZero(result[i]));
	}
	// ������ �������� ������������ ����
	sort(result_num.begin(), result_num.end(), comp);

	for (int i = 0; i < result_num.size(); i++) {
		cout << result_num[i] << '\n';
	}
}