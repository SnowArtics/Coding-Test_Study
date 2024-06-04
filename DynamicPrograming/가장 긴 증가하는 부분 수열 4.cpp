#include <bits/stdc++.h>

using namespace std;

int arr[1001];
int countArr[1001];
int checkArr[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	for (int i = 1; i < n+1; ++i) {
		cin >> arr[i];
		countArr[i] = 1;
		checkArr[i] = -1;
	}

	for (int i = 2; i < n + 1; ++i){ 
		for (int j = 1;j<i; ++j){
			if (arr[i] > arr[j] && (countArr[j]+1) > countArr[i]) {
				countArr[i] = countArr[j] + 1;
				checkArr[i] = j;
			}
		}
	}

	int a = 1, b = countArr[1];
	for (int i = 2; i< n+1; ++i) {
		if (b < countArr[i]) {
			a = i;
			b = countArr[i];
		}
	}

	deque<int> ans;
	int cur = a;
	while (cur) {
		ans.push_front(arr[cur]);
		cur = checkArr[cur];
	}
	ans.pop_front();
	cout << ans.size() << "\n";
	for (auto x : ans) cout << x << ' ';

	return 0;
}