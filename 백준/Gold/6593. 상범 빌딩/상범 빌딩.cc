#include <bits/stdc++.h>

#define GETTUPLE(n, tupleName) get<n>(tupleName)
#define GETALLTUPLE(tupleName) get<0>(tupleName), get<1>(tupleName), get<2>(tupleName)

using namespace std;

char mapArr[30][30][30];
int countMapArr[30][30][30];

tuple<int, int, int> startPoint;
tuple<int, int, int> endPoint;
int L, R, C;

void BFS() {
	int dx[6] = { 1,-1,0,0,0,0 };
	int dy[6] = { 0,0,1,-1,0,0 };
	int dz[6] = { 0,0,0,0,1,-1 };

	queue<tuple<int, int, int>> tupleQueue;
	tupleQueue.push(make_tuple(GETTUPLE(0, startPoint), GETTUPLE(1, startPoint), GETTUPLE(2, startPoint)));
	countMapArr[GETTUPLE(0, startPoint)][GETTUPLE(1, startPoint)][GETTUPLE(2, startPoint)] = 0;

	while (!tupleQueue.empty()) {
		tuple<int, int, int> tempTuple = make_tuple(GETALLTUPLE(tupleQueue.front()));
		tupleQueue.pop();

		int x, y, z;
		tie(z, y, x) = tempTuple;
		for (int i = 0; i < 6; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx < 0 || nx >= C || ny < 0 || ny >= R || nz < 0 || nz >= L) continue;
			if (countMapArr[nz][ny][nx] != -1) continue;
			if (mapArr[nz][ny][nx] == '#') continue;

			countMapArr[nz][ny][nx] = countMapArr[z][y][x] + 1;
			tupleQueue.push(make_tuple(nz, ny, nx));
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true) {
		cin >> L >> R >> C;
		
		if (L == 0)
			break;

		for (int i = 0; i < L; ++i) {
			for (int j = 0; j < R; ++j) {
				for (int k = 0; k < C; ++k) {
					cin >> mapArr[i][j][k];
					if (mapArr[i][j][k] == 'S')
						startPoint = make_tuple(i, j, k);
					if (mapArr[i][j][k] == 'E')
						endPoint = make_tuple(i, j, k);
				}
			}
		}

		for (int i = 0; i < L; ++i) {
			for (int j = 0; j < R; ++j) {
				for (int k = 0; k < C; ++k) {
					countMapArr[i][j][k] = -1;
				}
			}
		}

		BFS();

		int x, y, z;
		tie(z, y, x) = endPoint;
		if (countMapArr[z][y][x] == -1)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << countMapArr[z][y][x] << " minute(s).\n";
	}
	

	return 0;
}