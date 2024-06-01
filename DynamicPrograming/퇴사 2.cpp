#include <bits/stdc++.h>

using namespace std;

int T[1500001];
int P[1500001];
int result[1500001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	for (int i = 1; i < n + 1; ++i) cin >> T[i] >> P[i];

	for (int i = n; i > 0; --i) {
		if (T[i] + i <= n+1) {
			result[i] = max(result[i + 1], P[i] + result[i + T[i]]);
		}
		else
			result[i] = result[i + 1];
	}

	cout << *max_element(result + 1, result + n + 1);

	return 0;
}