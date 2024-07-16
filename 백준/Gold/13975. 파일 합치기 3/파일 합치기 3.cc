#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int k; cin >> k;
		priority_queue<long long, vector<long long>, greater<long long>> pQ;
		while (k--) {
			int num; cin >> num;
			pQ.push(num);
		}
		long long cost = 0;
		while (pQ.size() != 1) {
			long long num1, num2;
			num1 = pQ.top(); pQ.pop();
			num2 = pQ.top(); pQ.pop();
			cost += (num1 + num2);
			pQ.push(num1 + num2);
		}
		cout << cost << "\n";
	}

	return 0;
}