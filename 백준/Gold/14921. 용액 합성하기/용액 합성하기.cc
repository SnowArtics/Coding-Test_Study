#include <bits/stdc++.h>

using namespace std;

int arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr[i] = num;
	}

	int start = 0;
	int end = n - 1;

	int result = 200000002;

	while (start < end) {
		if(abs(result) > abs(arr[start] + abs(arr[end])))
			result = arr[start] + arr[end];

		if (abs(arr[start]) > abs(arr[end]))
			++start;
		else
			--end;
	}

	cout << result;

	return 0;
}