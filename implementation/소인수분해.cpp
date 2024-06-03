#include <bits/stdc++.h>

using namespace std;

vector<int> result;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			result.push_back(i);
			n = n / i;
			--i;
		}
	}

	if (n != 1)
		result.push_back(n);

	for (int n : result)
		cout << n << "\n";

	return 0;
}