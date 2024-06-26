#include <iostream>
#include<vector>	

using namespace std;

vector<pair<int, int>> vVector;
int arr1[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, x;
	cin >> n >> m >> x;

	for (int i = 1; i < n + 1; ++i)
		fill(arr1[i], arr1[i] + 1001, 0x3f3f3f3f);
	for (int i = 1; i < n + 1; ++i)
		arr1[i][i] = 0;

	for(int i=0;i<m;++i){
		int a, b, c;
		cin >> a >> b >> c;
		arr1[a][b] = c;
	}

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < n + 1; ++j) {
			for (int k = 1; k < n + 1; ++k) {
				arr1[j][k] = min(arr1[j][k], arr1[j][i] + arr1[i][k]);
			}
		}
	}

	int result = 0;
	for (int i = 1; i < n + 1; ++i) {
		int num = arr1[i][x] + arr1[x][i];
		if (result < num) result = num;
	}

	cout << result;

	return 0;
}