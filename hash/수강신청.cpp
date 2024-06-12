#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> vs;
	unordered_map<string, int> ms;

	for (int i = 0; i < m; ++i) {
		string num;
		cin >> num;
		ms[num]++;
		vs.push_back(num);
	}

	int count = 0;
	for (auto value : vs) {
		if (ms[value] == 1) {
			cout << value << "\n";
			++count;
		}
		else
			ms[value]--;

		if (count == n)
			return 0;
	}

	return 0;
}