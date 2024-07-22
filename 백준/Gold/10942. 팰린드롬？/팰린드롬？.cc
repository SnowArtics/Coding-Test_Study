#include <bits/stdc++.h>

using namespace std;

int input[2001];
int arr[2001][2001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i < n + 1; ++i)
		cin >> input[i];

	for (int i = 1; i < n + 1; ++i) {
		arr[i][i] = 1;
		if (input[i - 1] == input[i]) arr[i - 1][i] = 1;
	}

	for (int gap = 2; gap < n; ++gap) {
		for (int i = gap + 1; i < n + 1; ++i) {
			if (input[i - gap] == input[i] && arr[i - gap + 1][i-1])
				arr[i - gap][i] = 1;
		}
	}

	cin >> n;
	while (n--) {
		int num1, num2; cin >> num1 >> num2;
		cout << arr[num1][num2] << "\n";
	}


	return 0;
}