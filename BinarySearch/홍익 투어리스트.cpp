#include <bits/stdc++.h>

using namespace std;

vector<bool> goodPlace(500001);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	set<int> onePlace;

	int n, q;
	cin >> n >> q;

	int playerPos = 1;

	for (int i = 1; i < n+1; ++i) {
		bool mBool;
		cin >> mBool;
		goodPlace[i] = mBool;
		if (goodPlace[i])
			onePlace.insert(i);
	}

	for (int i = 0; i < q; ++i) {
		int num;
		cin >> num;

		if (num == 1) {
			int num1;
			cin >> num1;
			goodPlace[num1] = !goodPlace[num1];
			if (goodPlace[num1]) {
				onePlace.insert(num1);
			}
			else {
				onePlace.erase(num1);
			}
		}
		else if (num == 2) {
			int num1;
			cin >> num1;
			playerPos += num1;
			playerPos = (playerPos -1) % n + 1;
		}
		else if (num == 3) {
			if (onePlace.size() == 0) {
				cout << -1 << "\n";
			}
			else {
				auto it = onePlace.lower_bound(playerPos);
				if (it == onePlace.end())
					cout << (*(onePlace.begin()) + n - playerPos) << "\n";
				else
					cout << (*it - playerPos) << "\n";
			}			
		}
	}

	return 0;
}