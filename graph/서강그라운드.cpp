#include <bits/stdc++.h>

using namespace std;

int itemArr[101];
int arr[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 1; i < n + 1; ++i) {
		int num; cin >> num;
		itemArr[i] = num;
	}

	for (int i = 1; i < n + 1; ++i)
		fill(arr[i], arr[i] + 101, 0x3f3f3f3f);

	for (int i = 1; i < n + 1; ++i)
		arr[i][i] = 0;

	for (int i = 0; i < r; ++i) {
		int start, end, cost;
		cin >> start >> end >> cost;
		arr[start][end] = cost;
		arr[end][start] = cost;
	}

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			for (int k = 1; k < n + 1; ++k) {
				arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}

	int resultArr[101];
	fill(resultArr, resultArr + 101, 0);

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			if (arr[i][j] <= m) {
				resultArr[i] += itemArr[j];
			}
		}
	}

	cout << *max_element(resultArr, resultArr + 101);

	return 0;
}