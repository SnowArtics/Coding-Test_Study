#include <bits/stdc++.h>

using namespace std;

short arr[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	
	cin >> n;

	arr[1] = 1;
	arr[2] = 2;

	for (int i = 3; i < n + 1; ++i) {
		arr[i] = arr[i-1]+arr[i-2];
	}

	cout << arr[n];

	return 0;
}