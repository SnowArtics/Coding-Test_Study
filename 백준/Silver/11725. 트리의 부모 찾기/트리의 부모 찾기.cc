#include <bits/stdc++.h>

using namespace std;

vector<int> tree[100001];
int check[100001];
int parent[100001];

void DFS() {
	parent[1] = 0;

	stack<int> stack;
	stack.push(1);

	while (!stack.empty()) {
		int cur = stack.top();
		stack.pop();
		check[cur] = true;

		for (int i = 0; i < tree[cur].size(); ++i) {
			int nxt = tree[cur][i];
			if (check[nxt]) continue;
			parent[nxt] = cur;
			stack.push(nxt);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	for (int i = 0; i < n-1; ++i) {
		int num1, num2;
		cin >> num1 >> num2;

		tree[num1].push_back(num2);
		tree[num2].push_back(num1);
	}

	DFS();

	for (int i = 2; i < n+1; ++i) {
		cout << parent[i] << "\n";
	}

	return 0;
}