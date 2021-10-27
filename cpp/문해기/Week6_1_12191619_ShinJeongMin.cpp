#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

struct customerInfo {
	int useTime, cost;
};

struct counterInfo {
	int endTime, number;
};

struct cmp {
	bool operator()(counterInfo a, counterInfo b) {
		if (a.endTime == b.endTime)
		{
			return a.number > b.number;
		}
		return a.endTime > b.endTime;
	}
};

customerInfo customer[100001];
priority_queue<counterInfo, vector<counterInfo>, cmp> counterPQ;

int costAnswer[20001];
int N, M, timeAnswer;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> customer[i].useTime >> customer[i].cost;
	}

	// 계산대에 처음 손님들 세우기
	for (int i = 1; i <= N; i++) {
		counterPQ.push({ customer[i].useTime, i });
		costAnswer[i] += customer[i].cost;
		timeAnswer = max(timeAnswer, customer[i].useTime);
	}

	// 다음 대기 손님들 세우기
	for (int i = N+1; i <= M; i++) {
		counterInfo counterTemp = counterPQ.top();
		counterPQ.pop();
		counterTemp.endTime += customer[i].useTime;
		costAnswer[counterTemp.number] += customer[i].cost;
		timeAnswer = max(timeAnswer, counterTemp.endTime);
		counterPQ.push(counterTemp);
	}

	cout << timeAnswer << "\n";
	for (int i = 1; i <= N; i++) {
		cout << costAnswer[i] << "\n";
	}
}