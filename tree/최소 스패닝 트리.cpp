#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> VBE[100001];
bool vertex[10001];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pQ;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	cin >> v >> e;

	for (int i = 0; i < e; ++i) {
		int x, y, count;
		cin >> x >> y >> count;

		VBE[x].push_back(make_pair(y, count));
		VBE[y].push_back(make_pair(x, count));
	}

	vertex[1] = true;

	for (auto a : VBE[1]) {
		pQ.push({ a.second, 1, a.first });
	}

	int cnt = 0;
	int result = 0;
	while (cnt != v - 1) {
		int value, x, y;
		tie(value, x, y) = pQ.top(); pQ.pop();
		if (vertex[y]) continue;

		result += value;

		vertex[y] = true;
		cnt++;
		for (auto a : VBE[y]) {
			if (!vertex[a.first]) pQ.push({ a.second, y, a.first });
		}
	}

	cout << result;

	return 0;
}