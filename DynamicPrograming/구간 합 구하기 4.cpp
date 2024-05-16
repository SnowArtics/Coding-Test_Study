#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int resultArr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	cin >> arr[1];
	resultArr[1] = arr[1];
	for (int i = 2; i < n+1; ++i) {
		cin >> arr[i];
		resultArr[i] = arr[i];
		resultArr[i] += resultArr[i - 1];
	}

	for (int i = 1; i < m + 1; ++i) {
		int k, l;
		cin >> k >> l;

		int largeNum = resultArr[l];
		int smallNum;

		if (k == 1)
			smallNum = 0;
		else
			smallNum = resultArr[k-1];

		cout << largeNum - smallNum << "\n";
	}

	return 0;
}