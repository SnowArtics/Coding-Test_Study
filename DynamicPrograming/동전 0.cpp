#include <bits/stdc++.h>

using namespace std;

int arr[11];
int resultArr[11];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	int result = 0;

	cin >> n >> k;

	for (int i = 1; i < n + 1; ++i) {
		cin >> arr[i];
	}

	for (int i = n; i > 0; --i) {
		if (k >= arr[i]) {
			resultArr[i] = k / arr[i];
			k = k - arr[i] * resultArr[i];
			result += resultArr[i];
		}
		if (k == 0) {
			cout << result;
			return 0;
		}
	}

	return 0;
}