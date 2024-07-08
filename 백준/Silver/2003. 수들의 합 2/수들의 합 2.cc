#include <bits/stdc++.h>

using namespace std;

int arr[10000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int end = 0;
	int tempNum = arr[end];
	int result = 0;
	for (int start = 0; end < n; ++start) {
		while (tempNum < m) {
			++end;
			if (end == n) break;
			tempNum += arr[end];
		}
		if (tempNum == m) ++result;
		tempNum -= arr[start];
	}

	cout << result;

	return 0;
}