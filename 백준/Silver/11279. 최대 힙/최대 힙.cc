#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int> pQ;
	int n; cin >> n;
	while (n--) {
		int num; cin >> num;
		if (num != 0)
			pQ.push(num);
		else if (pQ.empty())
			cout << "0\n";
		else{
			cout << pQ.top() << "\n";
			pQ.pop();
		}
	}


	return 0;
}