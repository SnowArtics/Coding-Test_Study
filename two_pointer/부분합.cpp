#include <bits/stdc++.h>

using namespace std;

int arr[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int end = 0;
	int result = 1000000;
	int countNum = arr[end];
	for (int st = 0; st < n; ++st) {
		if (st > 0) countNum -= arr[st - 1];
		while (countNum < s && end != n) {
			++end;
			countNum += arr[end];
		}
		if (result > (end - st) && countNum >= s) result = end - st;
	}

	if (result == 1000000) cout << "0";
	else cout << ++result;

	return 0;
}