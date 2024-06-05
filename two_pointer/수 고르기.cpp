#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int n;
int m;

int Search() {
	int result = 2000000001;

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] - arr[i] >= m) {
				result = min(result, arr[j] - arr[i]);
				break;
			}
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);

	int result = Search();

	cout << result;

	return 0;
}