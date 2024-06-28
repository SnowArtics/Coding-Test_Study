#include<bits/stdc++.h>

using namespace std;

char arr[10000][10000];

void func(int _num, int _i, int _j) {
	if (_num == 1) return;

	int count = _num / 3;

	for (int i = _i; i < _num + _i; ++i) {
		for (int j = _j; j < _num + _j; ++j) {
			if (i % count == 0 && j % count == 0) func(count, i , j);
			if (i >= _i + count && i < _i + (count * 2) && j >= _j + count && j < _j + (count * 2)) arr[i][j] = ' ';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < 10000; ++i)
		fill(arr[i], arr[i] + 10000, '*');

	func(n, 0, 0);

	for (int i = 0; i < n; ++i)
		arr[i][n] = '\n';

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n + 1; ++j) {
			cout << arr[i][j];
		}
	}

	return 0;
}