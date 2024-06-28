#include <iostream>

using namespace std;

int arr[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < n + 1; ++i)
		cin >> arr[i];

	for (int i = 1; i < n + 1; ++i)
		for (int j = 1; j < i + 1; ++j)
			arr[i] = max(arr[i - j] + arr[j], arr[i]);
		
	cout << arr[n];

	return 0;
}