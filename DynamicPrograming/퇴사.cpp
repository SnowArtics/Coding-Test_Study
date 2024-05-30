#include <bits/stdc++.h>

using namespace std;

int T[20];
int P[20];
int revenue[20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;

	cin >> n;

	for (int i = 1; i < n + 1; ++i) cin >> T[i] >> P[i];
				
	for (int i = n; i > 0; --i) {
		if (i + T[i] <= n + 1)
			revenue[i] = max(revenue[i + T[i]] + P[i], revenue[i + 1]);
		else
			revenue[i] = revenue[i + 1];
	}

	cout << *max_element(revenue + 1, revenue + n + 1);

	return 0;
}