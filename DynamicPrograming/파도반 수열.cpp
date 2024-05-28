#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	long long arr[101];
	arr[1] = arr[2] = arr[3] = 1;
	arr[4] = arr[5] = 2;
	for (int j = 6; j < 101; ++j) {
		arr[j] = arr[j - 2] + arr[j - 3];
	}

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		cout << arr[num] << "\n";
	}

	return 0;
}