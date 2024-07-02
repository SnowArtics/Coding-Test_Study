#include<bits/stdc++.h>

using namespace std;

int arr[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	//n이 x일때 만들 수 있는 경우의 수 x;
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	arr[4] = 5;

	for (int i = 5; i < n + 1; ++i) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	}

	cout << arr[n];

	return 0;
}