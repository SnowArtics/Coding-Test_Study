#include <bits/stdc++.h>

using namespace std;

vector<int> tree[100001];
int parent[100001];
int query[100001];

int DFS(int _start) {
	int num = 0;
	int parentNum = 0;
	for (auto nxt : tree[_start]) {
		if (parent[_start] == nxt) continue;
		parent[nxt] = _start;
		num += DFS(nxt);
		++parentNum;
	}
	query[_start] = num + parentNum;
	return num + parentNum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, q;
	cin >> n >> r >> q;

	for (int i = 0; i < n-1; ++i) {
		int num1, num2;
		cin >> num1 >> num2;

		tree[num1].push_back(num2);
		tree[num2].push_back(num1);
	}

	DFS(r);

	for (int i = 0; i < q; ++i) {
		int num;
		cin >> num;
		cout << query[num] + 1 << "\n";
	}
}