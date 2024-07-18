#include <bits/stdc++.h>

using namespace std;

vector<int> graph[51];
int depth[51];
bool check[51];

int BFS(int _start) {
	queue<int> iQ;
	iQ.push(_start);
	int resultNum = 0;
	while (!iQ.empty()) {
		int cur = iQ.front(); iQ.pop();
		check[cur] = true;
		for (auto nxt : graph[cur]) {
			if (check[nxt]) continue;
			iQ.push(nxt);
			if(depth[nxt] ==0) depth[nxt] = depth[cur] + 1;
			if (depth[nxt] > resultNum) resultNum = depth[nxt];
		}
	}

	return resultNum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	while (true) {
		int num1, num2; cin >> num1 >> num2;
		if (num1 == -1) break;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
	}

	int result[51];
	int minNum = 51;
	for (int i = 1; i < n + 1; ++i) {
		fill(depth, depth + 51, 0);
		fill(check, check + 51, false);
		result[i] = BFS(i);
		if (result[i] < minNum) minNum = result[i];
	}
	
	vector<int> resultList;
	for (int i = 1; i < n + 1; ++i) {
		if (result[i] == minNum) resultList.push_back(i);
	}

	cout << minNum << " " << resultList.size()<<"\n";
	for (auto cur : resultList)
		cout << cur << " ";

	return 0;
}