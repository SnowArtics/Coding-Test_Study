#include <bits/stdc++.h>

using namespace std;

int arr[10][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < 10; ++i) {
		arr[i][1] = 1;
	}

	for (int i = 2; i < n + 1; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k <= j; ++k) {
				arr[j][i] += arr[k][i - 1];
				arr[j][i] %= 10007;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 10; ++i)
		result += arr[i][n];

	cout << result % 10007;

	return 0;
}