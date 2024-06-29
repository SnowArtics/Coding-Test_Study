#include <bits/stdc++.h>

using namespace std;

int arr[2][100001];
int resultArr[2][100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;

		for (int i = 0; i < 2; ++i) {
			for (int j = 1; j < n+1;++j) {
				cin >> arr[i][j];
			}
		}

		resultArr[0][1] = arr[0][1];
		resultArr[1][1] = arr[1][1];

		for (int i = 2; i < n+1; ++i) {
			for (int j = 0; j < 2; ++j) {
				resultArr[j][i] = max(resultArr[abs(j - 1)][i - 1] + arr[j][i], resultArr[abs(j - 1)][i - 2] + arr[j][i]);
			}
		}

		int result = max(resultArr[0][n], resultArr[1][n]);
		cout << result << "\n";
	}

	return 0;
}