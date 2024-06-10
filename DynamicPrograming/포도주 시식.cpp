#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int arr[10001];
	int resultArr[10001];

	for (int i = 1; i < n+1; ++i) {
		cin >> arr[i];
	}

	resultArr[1] = arr[1];
	resultArr[2] = resultArr[1] + arr[2];

	for (int i = 3; i < n+1; ++i) {
		resultArr[i] = max({ resultArr[i - 1], resultArr[i - 2] + arr[i], resultArr[i - 3] + arr[i - 1] + arr[i] });
	}

	cout << resultArr[n];

	return 0;
}