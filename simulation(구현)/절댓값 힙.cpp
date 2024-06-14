#include <bits/stdc++.h>

using namespace std;

vector<bool> goodPlace(500001);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int> maxQueue;
	priority_queue<int, vector<int>, greater<int>> minQueue;

	int n;
	cin >> n;
	n++;

	while (--n) {
		int num;
		cin >> num;
		if (num > 0) {
			minQueue.push(num);
		}
		else if (num < 0) {
			maxQueue.push(num);
		}
		else {
			if (minQueue.empty() && maxQueue.empty()) {
				cout << "0\n";
				continue;
			}
			else if (minQueue.empty()) {
				cout << maxQueue.top() << "\n";
				maxQueue.pop();
				continue;
			}
			else if (maxQueue.empty()) {
				cout << minQueue.top() << "\n";
				minQueue.pop();
				continue;
			}

			int minTop = abs(minQueue.top());
			int maxTop = abs(maxQueue.top());

			if (minTop < maxTop) {
				cout << minTop << "\n";
				minQueue.pop();
			}
			else if (minTop > maxTop) {
				cout << -maxTop << "\n";
				maxQueue.pop();
			}
			else if (minTop == maxTop) {
				cout << -maxTop << "\n";
				maxQueue.pop();
			}
		}
	}

	return 0;
}