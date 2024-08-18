#include <bits/stdc++.h>

using namespace std;

int arr[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int answer = 0;
	int n, k; cin >> n >> k;

	for (int i = 1; i <= k; ++i) {
		cin >> arr[i];
	}

	vector<int> concent(n + 1);
	int start = 1;
	int concentStart = 1;
	for (int i = 1; concent[n] == 0; ++i) { // 콘센트에 다 넣음
		if (find(concent.begin() + 1, concent.end(), arr[i]) != concent.end()) continue;
		concent[concentStart] = arr[i];
		start = i;
		++concentStart;
	}
	++start;

	for (int i = start; i < k + 1; ++i) {
		if (find(concent.begin() + 1, concent.end(), arr[i]) != concent.end()) continue; // concent에 이미 값이 있다면 건너뜀
		int checkCount = -1;
		int checkNum = -1;
		for (int j = 1; j < concent.size(); ++j) {//가장 멀리 있는 콘센트 위치를 찾음.
			int range = 0;
			for (int p = i + 1; p < k + 1; ++p) {//가장 멀리 있는 콘센트의 범위 구하기
				if (arr[p] == concent[j]) break;
				++range;
			}
			if (range > checkCount) {
				checkCount = range;
				checkNum = j;
			}
		}
		concent[checkNum] = arr[i];
		++answer;
	}

	cout << answer;

	return 0;
}