#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> vVector[1001];
int n, m, x;

int dikstra(int _start, int _end) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ;
	int vertex[1001];
	fill(vertex, vertex + 1001, 0x3f3f3f3f);

	vertex[_start] = 0;
	pQ.push({ vertex[_start], _start });

	while (!pQ.empty()) {
		auto cur = pQ.top(); pQ.pop();
		if (vertex[cur.second] != cur.first) continue;
		for (auto nxt : vVector[cur.second]) {
			if (vertex[nxt.second] <= vertex[cur.second] + nxt.first) continue;
			vertex[nxt.second] = vertex[cur.second] + nxt.first;
			pQ.push({ vertex[nxt.second], nxt.second });
		}
	}

	return vertex[_end];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> x;

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		vVector[a].push_back({ c,b });
	}

	int result = 0;
	for (int i = 1; i < n + 1; ++i) {
		int num1 = dikstra(x, i);
		int num2 = dikstra(i, x);
		int num3 = num1 + num2;
		if (num3 > result) result = num3;
	}

	cout << result;

	return 0;
}