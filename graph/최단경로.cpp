#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> vVertex[20001];
int vertex[20001];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pQ;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int v, e;
	cin >> v >> e;

	int start;
	cin >> start;

	fill(vertex, vertex + 20001, 0x3f3f3f3f);

	for (int i = 0; i < e; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		vVertex[a].push_back(make_pair(c, b));
	}

	vertex[start] = 0;
	pQ.push(make_pair(0, start));

	while (!pQ.empty()) {
		int cost = pQ.top().first;
		int cur = pQ.top().second;
		pQ.pop();
		if (vertex[cur] != cost) continue;
		for (int i = 0; i < vVertex[cur].size(); ++i) {
			int nxt = vVertex[cur][i].second;
			int nxtCost = vertex[cur] + vVertex[cur][i].first;
			if (vertex[nxt] < nxtCost) continue;
			vertex[nxt] = nxtCost;
			pQ.push(make_pair(nxtCost, nxt));
		}
	}

	for (int i = 1; i < v + 1; ++i) {
		if (vertex[i] == 0x3f3f3f3f) cout << "INF\n";
		else cout << vertex[i] << "\n";
	}

	return 0; 
}