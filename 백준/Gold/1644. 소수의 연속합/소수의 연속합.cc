#include <bits/stdc++.h>

using namespace std;

const int MXN = 4000002;
vector<bool> seive(MXN, true);
vector<int> primes;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 2; i * i < n+1; i++) {
		if (!seive[i]) continue;
		for (int j = i * i; j < n+1; j += i)
			seive[j] = false;
	}

	for (int i = 2; i < n+1; i++) if (seive[i]) primes.push_back(i);

	int st = 0, end = 0;
	int num = 0;
	if(primes.size() >0) num = primes[st];
	int result = 0;
	for (st = 0; st < primes.size(); ++st) {
		if(st > 0 ) num -= primes[st - 1];
		while (num < n && end < primes.size()) {
			++end;
			if(end == primes.size()) break;
			num += primes[end];
		}
		if (num == n) ++result;
	}

	cout << result;

	return 0;
}