#include <bits/stdc++.h>

using namespace std;

int arr[2000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	n += 1000001;

	if(n == 1000001)
		cout << "0\n";

	arr[1000001] = 0;
	arr[1000002] = 1;

	if (n > 1000001) {
		for (int i = 1000003; i <= n; ++i)
			arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000000;
		cout << "1\n";
	}
	else if (n < 1000001) {
		for (int i = 1000002; i > 1; --i)
			arr[i - 2] = (arr[i] - arr[i - 1]) % 1000000000;
		if (abs(n) % 2 == 0)
			cout << "1\n";
		else
			cout << "-1\n";
	}

	cout << abs(arr[n]);

	return 0;
}