#include <bits/stdc++.h>

using namespace std;

int input[1001][1001];
int arr[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 1; i < n + 1; ++i) {
		string s; cin >> s;
		for (int j = 1; j < m + 1; ++j)
			input[i][j] = s[j - 1] - '0';
	}

	int result = 0;
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < m + 1; ++j) {
			if (input[i][j]) {
				arr[i][j] = min({ arr[i - 1][j], arr[i][j - 1], arr[i - 1][j - 1] }) + 1;
				result = max(result, arr[i][j]);
			}
		}
	}

	cout << result*result;

	return 0; 
}