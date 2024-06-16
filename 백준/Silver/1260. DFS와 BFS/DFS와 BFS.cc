#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1001];
bool check[1001];

vector<int> BFS(int _start) {
	fill(check, check + 1001, false);

	vector<int> result;

	queue<int> qQ;
	qQ.push(_start);
	check[_start] = true;

	while (!qQ.empty()) {
		int cur = qQ.front();
		qQ.pop();
		result.push_back(cur);
		for (int i = 0; i < graph[cur].size(); ++i) {
			int nxt = graph[cur][i];
			if (check[nxt]) continue;
			qQ.push(nxt);
			check[nxt] = true;
		}
	}

	return result;
}

vector<int> DFS(int _start) {
	fill(check, check + 1001, false);

	vector<int> result;

	stack<int> qQ;
	qQ.push(_start);

	while (!qQ.empty()) {
		int cur = qQ.top();
		qQ.pop();
		if(check[cur]) continue;
		check[cur] = true;
		result.push_back(cur);
		for (int i = 0; i < graph[cur].size(); ++i) {
			int nxt = graph[cur][graph[cur].size()-1-i];
			if (check[nxt]) continue;
			qQ.push(nxt);
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, v;
	cin >> n >> m >> v;

	for (int i = 0; i < m; ++i) {
		int num1, num2;
		cin >> num1 >> num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
	}

	for (int i = 1; i < n+1; ++i) {
		sort(graph[i].begin(), graph[i].end());
	}

	vector<int> DFSResult = DFS(v);
	vector<int> BFSResult = BFS(v);

	for (int i = 0; i < DFSResult.size(); ++i) {
		cout << DFSResult[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < BFSResult.size(); ++i) {
		cout << BFSResult[i] << " ";
	}

	return 0;
}