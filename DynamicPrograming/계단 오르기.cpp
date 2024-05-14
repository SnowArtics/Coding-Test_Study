#include <bits/stdc++.h>

using namespace std;

int arr[301];
int resultArr[301];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int result = 0;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		result += arr[i];
	}

	if (n < 3) {
		cout << result;
		return 0;
	}
	
	resultArr[0] = arr[0];
	resultArr[1] = arr[1];
	resultArr[2] = arr[2];

	for (int i = 3; i < n; ++i) {
		resultArr[i] = min(resultArr[i - 2], resultArr[i - 3]) + arr[i];
	}

	cout << max(result - resultArr[n - 2], result - resultArr[n - 3]);

	return 0;
}