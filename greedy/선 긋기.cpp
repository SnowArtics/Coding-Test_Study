#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> arr;	

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int k = 0;

	for (int i = 0; i < n; ++i) {
		int num1, num2;
		cin >> num1 >> num2;
		arr.push_back({ num1,num2 });
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; ++i) {
		if (arr[i].first == 1000000001) continue;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j].first == 1000000001) continue;
			if (arr[j].first >= arr[i].first && arr[j].first <= arr[i].second) {
				if (arr[j].second > arr[i].second) arr[i].second = arr[j].second;
				arr[j].first = 1000000001;
			}
		}
	}
	
	int result = 0;
	for (int i = 0; i < n; ++i) {
		auto a = arr[i];
		if (a.first == 1000000001) continue;
		result += (a.second - a.first);
	}

	cout << result;
	return 0;
}