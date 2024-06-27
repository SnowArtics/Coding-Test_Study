#include <bits/stdc++.h>

using namespace std;

int arrDP[100001][101];
vector<pair<int, int>> vArr;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < 101; ++i)
		fill(arrDP[i], arrDP[i] + 101, 0);

	vArr.push_back({ 0,0 });
	for (int i = 0; i < n; ++i) {
		int num1, num2;
		cin >> num1 >> num2;
		vArr.push_back({ num1,num2 });
	}

	for (int i = 0; i < n; ++i)
		arrDP[0][i] = 0;

	for (int i = 1; i < k + 1; ++i) {
		for (int j = 1; j < n+1; ++j) {
			int weight = vArr[j].first;
			int value = vArr[j].second;
			if (i >= weight)
				arrDP[i][j] = max( arrDP[i - weight][j - 1] + value, arrDP[i][j - 1]);
			else
				arrDP[i][j] = max(arrDP[i][j - 1], arrDP[i][j - 1]);
		}
	}

	int num = 0;
	for (int i = 0; i < k + 1; ++i) {
		for (int j = 0; j < n + 1; ++j) {
			if (num < arrDP[i][j]) 
				num = arrDP[i][j];
		}
	}

	cout << num;

	return 0;
}