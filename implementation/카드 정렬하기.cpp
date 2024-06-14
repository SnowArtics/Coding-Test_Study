#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pQ;

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		pQ.push(num);
	}

	int result = 0;
	
	while (pQ.size()>1) {
		int num1 = pQ.top();
		pQ.pop();
		int num2 = pQ.top();
		pQ.pop();
		result += (num1 + num2);
		pQ.push(num1 + num2);
	}

	cout << result;

	return 0;
}