#include <bits/stdc++.h>

using namespace std;

vector<int> arr[50];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n; int startNum = 0;
	for (int i = 0; i < n; ++i) {
		int num; cin >> num;
		if (num == -1) {
			startNum = i;
			continue;
		}
		arr[num].push_back(i);
	}

	int deleteNum; cin >> deleteNum;
	arr[deleteNum].clear();

	if (deleteNum == startNum) {
		cout << "0";
		return 0;
	}

	stack<int> qQ;
	qQ.push(startNum);
	int result = 0;
	while (!qQ.empty()) {
		int cur = qQ.top(); qQ.pop();
		int count = 0;
		for (auto nxt : arr[cur]) {
			if (nxt == deleteNum) continue;
			qQ.push(nxt);
			++count;
		}
		if (count == 0) ++result;
	}

	cout << result;

	return 0;
}