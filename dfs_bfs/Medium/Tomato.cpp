#include "bits/stdc++.h"

using namespace std;

int arr[1002][1002];
int result[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n;

	queue<pair<int, int>> Q;

	int RipedTomato = 0;
	for (int i = 0; i < n; i++) {
		fill(result[i], result[i] + m, 0);
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			arr[i][j] = a;

			if (a == 1) {
				++RipedTomato;
				Q.push({ i,j });
			}
		}
	}

	if (RipedTomato == n * m) {
		cout << 0;
		return 0;
	}

	if (Q.empty()) {
		cout << -1;
		return 0;
	}

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.second + dx[i];
			int ny = cur.first + dy[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (arr[ny][nx] != 0 || result[ny][nx] > 0) continue;
			result[ny][nx] = result[cur.first][cur.second] + 1;
			Q.push({ ny,nx });
			if (arr[ny][nx] == 0) arr[ny][nx] = 1;
		}
	}

	int maxResult = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				cout << -1;
				return 0;
			}

			if (maxResult < result[i][j]) {
				maxResult = result[i][j];
			}
		}
	}

	cout << maxResult;

	return 0;
}