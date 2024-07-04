#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int count = 0;
	while (true) {
		int n;
		cin >> n;

		if (n == 0) break;

		for (int i = 0; i < n; ++i) {
			int num1, num2, num3;
			cin >> num1 >> num2 >> num3;
			arr[i][0] = num1; arr[i][1] = num2; arr[i][2] = num3;
		}

		arr[0][2] += arr[0][1];
		arr[1][0] += arr[0][1];
		arr[1][1] = min({ arr[0][1], arr[0][2], arr[1][0] }) + arr[1][1];
		arr[1][2] = min({ arr[0][1], arr[0][2], arr[1][1] }) + arr[1][2];
		for (int i = 2; i < n; ++i) {
			arr[i][0] = min(arr[i - 1][0], arr[i - 1][1]) + arr[i][0];
			arr[i][1] = min({ arr[i - 1][0], arr[i - 1][1], arr[i - 1][2], arr[i][0]}) + arr[i][1];
			arr[i][2] = min({ arr[i - 1][1], arr[i - 1][2], arr[i][1] }) + arr[i][2];
		}

		++count;
		cout << count << ". " << arr[n - 1][1] << "\n";
	}

	return 0;
}