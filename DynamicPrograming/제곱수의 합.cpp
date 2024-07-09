#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < n + 1; ++i) {
		arr[i] = i;
		for (int j = 1; j * j <= i; ++j) {
			arr[i] = min(arr[i], arr[i - j * j] + 1);
		}
	}

	cout << arr[n];

	return 0;
}