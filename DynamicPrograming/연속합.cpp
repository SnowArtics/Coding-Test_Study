#include <bits/stdc++.h>

using namespace std;

int input[100005];
int arr[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 1; i < n+1; ++i) {
		cin >> input[i];
	}

	arr[1] = input[1];
	for (int i = 2; i < n + 1; ++i) {
		arr[i] = max(0, arr[i - 1])+ input[i];
	}

	cout << *max_element(arr + 1, arr + n + 1);

	return 0;
}