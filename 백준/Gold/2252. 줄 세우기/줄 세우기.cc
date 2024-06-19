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
		int num1, num2;
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		indegree[num2]++;
	}

	queue<int> parent;
	for (int i = 1; i < n + 1; ++i)
		if (indegree[i] == 0) parent.push(i);

	while (!parent.empty()) {
		int cur = parent.front(); parent.pop();
		cout << cur << " ";
		for (auto nxt : graph[cur]) {
			indegree[nxt]--;
			if (indegree[nxt] == 0) parent.push(nxt);
		}
	}

	return 0;
}