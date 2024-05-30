#include <bits/stdc++.h>

using namespace std;

int inputArr[1005];
int countArr[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < n + 1; ++i) {
		cin >> inputArr[i];
		countArr[i] = 1;
	}

	for (int i = 2; i < n + 1; ++i) {
		for (int j = 1; j < i; ++j) {
			if (inputArr[j] < inputArr[i]) countArr[i] = max(countArr[i], countArr[j] + 1);
		}
	}

	cout << *max_element(countArr + 1, countArr + n + 1);
}