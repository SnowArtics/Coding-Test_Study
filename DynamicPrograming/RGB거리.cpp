#include <bits/stdc++.h>

using namespace std;

int arr[1003][3];
int resultArr[1003][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	
	cin >> n;

	for (int i = 1; i < n+1; ++i) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	resultArr[1][0] = arr[1][0];
	resultArr[1][1] = arr[1][1];
	resultArr[1][2] = arr[1][2];

	for (int i = 2; i < n + 1; ++i) {
		resultArr[i][0] = min(resultArr[i - 1][1], resultArr[i - 1][2]) + arr[i][0];
		resultArr[i][1] = min(resultArr[i - 1][0], resultArr[i - 1][2]) + arr[i][1];
		resultArr[i][2] = min(resultArr[i-1][0], resultArr[i-1][1]) + arr[i][2];
	}

	cout << *min_element(resultArr[n], resultArr[n]+ 3);

	return 0;
}