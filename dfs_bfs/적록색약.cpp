#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string mapArr[100];
	bool visit[100][100];
	for (int i = 0; i < n; ++i)
		fill(visit[i], visit[i] + n, true);

	for (int i = 0; i < n; ++i) {
		cin >> mapArr[i];
	}

	int dx[4] = {0,1,0,-1};
	int dy[4] = { 1,0, -1,0 };

	

	int resultCount1 = 0;
	int resultCount2 = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visit[i][j]) continue;

			stack<pair<int, int>> stackPos;
			stackPos.push(make_pair(i, j));
			int rangeType = 0;
			while (!stackPos.empty()) {
				pair<int, int> pos = stackPos.top();
				stackPos.pop();
				rangeType = mapArr[pos.first][pos.second];
				for (int i = 0; i < 4; ++i) {
					int ny = pos.first + dy[i];
					int nx = pos.second + dx[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (rangeType != mapArr[ny][nx]) continue;
					if (visit[ny][nx] != true) continue;
					stackPos.push(make_pair(ny, nx));
				}
				visit[pos.first][pos.second] = false;
			}

			++resultCount1;
		}
	}

	for (int i = 0; i < n; ++i)
		fill(visit[i], visit[i] + n, true);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (mapArr[i][j] == 'G')
				mapArr[i][j] = 'R';
		}
	}


	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visit[i][j]) continue;

			stack<pair<int, int>> stackPos;
			stackPos.push(make_pair(i, j));
			int rangeType = 0;
			while (!stackPos.empty()) {
				pair<int, int> pos = stackPos.top();
				stackPos.pop();
				rangeType = mapArr[pos.first][pos.second];
				for (int i = 0; i < 4; ++i) {
					int ny = pos.first + dy[i];
					int nx = pos.second + dx[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (rangeType != mapArr[ny][nx]) continue;
					if (visit[ny][nx] != true) continue;
					stackPos.push(make_pair(ny, nx));
				}
				visit[pos.first][pos.second] = false;
			}

			++resultCount2;
		}
	}

	cout << resultCount1 << " " << resultCount2;

	return 0;
}