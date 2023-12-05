#include "bits/stdc++.h"

using namespace std;

string arr[102];
int result[102][102];
int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void main() {	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i <n; i++) {
		fill(result[i], result[i] + m, 0);
	}

	queue<pair<int, int>> queue;
	queue.push({ 0,0 });
	result[0][0] = 0;
	while (!queue.empty()) {
		pair<int, int> curQueue = queue.front();
		queue.pop();

		for (int i = 0; i < 4; i++) {
			int numX = curQueue.second + dx[i];
			int numY = curQueue.first + dy[i];
			if (numX < 0 || numX >= m || numY < 0 || numY >= n) continue;
			if (arr[numY][numX] != '1' || result[numY][numX] > 0) continue;
			result[numY][numX] = result[curQueue.first][curQueue.second] + 1;
			queue.push({ numY,numX });
		}
	}

	cout << result[n-1][m-1] + 1;
}