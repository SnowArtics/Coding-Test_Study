#include <bits/stdc++.h>

using namespace std;


vector<int> IsPrime(int m, int n) {
	vector<int> primes;
	vector<bool> isPrime(n+1, true);

	isPrime[1] = false;
	for (int i = 2; i * i < n+1; ++i) {
		if (!isPrime[i]) continue;
		for (long long j = i * i; j < n+1; j+=i) {
			isPrime[j] = false;
		}
	}

	for (int i = m; i < n+1; ++i) {
		if (isPrime[i]) primes.push_back(i);
	}

	return primes;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> m >> n;

	vector<int>result = IsPrime(m, n);

	for (int i : result)
		cout << i << "\n";

	return 0;
}