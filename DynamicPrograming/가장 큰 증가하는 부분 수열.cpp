#include <bits/stdc++.h>

using namespace std;

int input[1005];
int arr[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 1; i < n+1; ++i) {
		cin >> input[i];
		arr[i] = input[i];
	}

	for (int i = 2; i < n + 1; ++i) {
		for (int j = 1; j < i; ++j) {
			if (input[j] < input[i]) arr[i] = max(arr[i], arr[j] + input[i]);
		}
	}

	cout << *max_element(arr + 1, arr + n + 1);

	return 0;
}