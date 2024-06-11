#include <bits/stdc++.h>

using namespace std;

int arr[41];
int countArr[41];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= m; ++i)
		cin >> arr[i];

	countArr[0] = 1;
	countArr[1] = 1;
	countArr[2] = 2;
	countArr[3] = 3;
	countArr[4] = 5;
	countArr[5] = 8;

	for (int i = 6; i < 41; ++i)
		countArr[i] = countArr[i - 1] + countArr[i - 2];

	int result = 1;

	for (int i = 1; i <= m; ++i) {
		int num = arr[i] - arr[i-1]-1;
		result *= countArr[num];
	}
	
	int num = n - arr[m];
	result *= countArr[num];

	cout << result;

	return 0;
}