#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1001];
bool check[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int num1, num2;
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
	}

	int result = 0;
	for (int k = 1; k < n + 1; ++k) {
		if (check[k])continue;
		++result;
		stack<int> qQ;
		qQ.push(k);
		while (!qQ.empty()) {
			int num = qQ.top();
			qQ.pop();
			check[num] = true;
			for (int i = 0; i < graph[num].size(); ++i) {
				int nxt = graph[num][i];
				if (check[nxt]) continue;
				qQ.push(nxt);
			}
		}
	}
	
	cout << result;

	return 0;
}