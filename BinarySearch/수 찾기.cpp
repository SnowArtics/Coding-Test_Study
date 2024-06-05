#include <bits/stdc++.h>

using namespace std;

int arr[100001];
int checkArr[100001];

int BinarySearch(int _num, int _size) {
	int st = 0;
	int en = _size;

	while (st <= en) {
		int mid = (st + en) / 2;
		if (arr[mid] < _num)
			st = mid + 1;
		else if (arr[mid] < _num)
			en = mid - 1;
		else
			return 1;
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> checkArr[i];

	for (int i = 0; i < m; ++i)
		cout << BinarySearch(checkArr[i], n);

	return 0;
}