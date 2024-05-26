#include <bits/stdc++.h>

using namespace std;

long long arr[92][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;

	cin >> n;

	arr[1][0] = 0;
	arr[1][1] = 1;

	for (int i = 2; i < n+1; i++) {
		arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
		arr[i][1] = arr[i - 1][0];
	}

	cout << arr[n][0] + arr[n][1];

	return 0;
}