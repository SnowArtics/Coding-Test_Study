#include <bits/stdc++.h>

using namespace std;

vector<int> graph[32001];
int indegree[32001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int a ,b ,c;
		cin >> a;
		cin >> b;
		while (--a) {
			cin >> c;
			graph[b].push_back(c);
			indegree[c]++;
			swap(b, c);
		}
	}

	queue<int> qQ;
	vector<int> result;

	for (int i = 1; i < n + 1; ++i)
		if (indegree[i] == 0) qQ.push(i);

	while (!qQ.empty()) {
		int num = qQ.front(); qQ.pop();
		result.push_back(num);
		for (auto nxt : graph[num]) {
			indegree[nxt]--;
			if (indegree[nxt] == 0) qQ.push(nxt);
		}
	}

	if (result.size() != n) cout << "0";
	else {
		for (auto num : result)
			cout << num << "\n";
	}

	return 0;
}