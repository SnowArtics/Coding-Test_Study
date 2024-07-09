#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	

	int tc; cin >> tc;
	
	while (tc--) {
		unordered_map<string, int> map;
		int n; cin >> n;
				
		while (n--) {
			string a, b;
			cin >> a >> b;
			map[b]++;			
		}

		int ans = 1;
		for (auto a : map) ans *= (a.second + 1);

		cout << ans - 1 << "\n";
	}

	return 0;
}