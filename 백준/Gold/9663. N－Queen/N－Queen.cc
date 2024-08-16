#include <iostream>

using namespace std;

bool check1[40];
bool check2[40];
bool check3[40];
int n;
int result = 0;

void func(int _cur) {
	if (_cur == n) {
		++result;
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (check1[i] || check2[i + _cur] || check3[_cur-i + n - 1])
			continue;
		check1[i] = true;
		check2[i + _cur] = true;
		check3[_cur - i + n - 1] = true;
		func(_cur + 1);
		check1[i] = false;
		check2[i + _cur] = false;
		check3[_cur - i + n - 1] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	func(0);
	cout << result;

	return 0;
}