#include <bits/stdc++.h>

using namespace std;

int arr[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 101; ++i)
		fill(arr[i], arr[i] + 101, 100000000);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int start, end, cost;
		cin >> start >> end >> cost;
		arr[start][end] = min(arr[start][end], cost);
	}

	for (int i = 1; i < n + 1; ++i) {
		arr[i][i] = 0;
	}

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			for (int k = 1; k < n + 1; ++k) {
				arr[j][k] = min(arr[j][k], arr[j][i]+arr[i][k]);
			}
		}
	}

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			if (arr[i][j] == 100000000) cout << "0 ";
			else cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}