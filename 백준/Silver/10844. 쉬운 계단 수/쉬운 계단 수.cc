#include <bits/stdc++.h>

using namespace std;

long long arr[101][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;
	
	for (int i = 1; i < 10; ++i) arr[1][i] = 1;

	for (int i = 2; i < n + 1; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (j != 0) arr[i][j] += arr[i - 1][j - 1];
			if (j != 9) arr[i][j] += arr[i - 1][j + 1];
			arr[i][j] %= 1000000000;
		}
	}

	long long result = 0;
	for (int i = 0; i < 10; ++i) result += arr[n][i];
	result %= 1000000000;

	cout << result;

	return 0;
}