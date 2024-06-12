#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	unordered_map<string, string> uMap;

	for (int i = 0; i < n; ++i) {
		string s1, s2;
		cin >> s1 >> s2;
		uMap[s1] = s2;
	}

	for (int i = 0; i < m; ++i) {
		string s1;
		cin >> s1;
		cout << uMap[s1] << "\n";
	}

	return 0;
}