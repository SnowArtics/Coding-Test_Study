#include <bits/stdc++.h>

using namespace std;

int arr[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;

	cin >> n;

	for (int i = 1; i < n + 1; ++i) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + n + 1);

	int result = 0;
	for (int i = 1; i < n + 1; ++i) {
		result = max(result, arr[n + 1 - i] * i);
	}

	cout << result;

	return 0;
}