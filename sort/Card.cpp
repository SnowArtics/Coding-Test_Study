#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	map<long long, int> m_map;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		long long m;
		cin >> m;
		m_map[m]++;
	}

	int count = 0;
	long long result = 0;
	for (auto it : m_map) {
		if (it.second > count) {
			count = it.second;
			result = it.first;
		}
	}

	cout <<result;
}