#include <bits/stdc++.h>

using namespace std;

long long arr[101][10];

bool IsPrime(int n) {
	if (n == 1) return 0;

	for (int i = 2; i < n; ++i)
		if (n % i == 0) return 0;

	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	int result = 0;

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;

		result += IsPrime(num);
	}

	cout << result;

	return 0;
}