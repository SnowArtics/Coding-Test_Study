#include <bits/stdc++.h>

using namespace std;

stack<int> s[4];
queue<pair<int,int>> qResult;

void hanoi(int _num, int _start, int _sub, int _end) {
	if (_num == 1) {
		int num = s[_start].top(); s[_start].pop();
		s[_end].push(num);
		qResult.push({ _start, _end });
		return;
	}
	else {
		hanoi(_num - 1, _start, _end, _sub);
		int num = s[_start].top(); s[_start].pop();
		s[_sub].push(num);
		qResult.push({ _start,_end });
		hanoi(_num - 1, _sub, _start, _end);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < n + 1; ++i) {
		s[1].push(i);
	}

	hanoi(n, 1, 2, 3);

	cout << qResult.size() << "\n";
	while (!qResult.empty()) {
		cout << qResult.front().first << " " << qResult.front().second << "\n";
		qResult.pop();
	}

	return 0;
}