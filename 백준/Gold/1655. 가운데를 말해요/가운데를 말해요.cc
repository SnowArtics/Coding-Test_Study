#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	priority_queue<int> maxPQ; // 낮은 수들
	priority_queue<int, vector<int>, greater<int>> minPQ; // 높은 수들
	int num; cin >> num; maxPQ.push(num); --n;
	cout << maxPQ.top() << "\n";
	while (n--) {
		int num; cin >> num;
		if (maxPQ.size() > minPQ.size()) minPQ.push(num);
		else maxPQ.push(num);
		while (maxPQ.top() > minPQ.top()) {
			int maxNum, minNum;
			maxNum = maxPQ.top(); maxPQ.pop();
			minNum = minPQ.top(); minPQ.pop();
			minPQ.push(maxNum);
			maxPQ.push(minNum);
		}

		cout << maxPQ.top() << "\n";
	}

	return 0;
}