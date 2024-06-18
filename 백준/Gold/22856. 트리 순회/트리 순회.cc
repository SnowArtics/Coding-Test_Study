#include <bits/stdc++.h>

using namespace std;

int l[100001];
int r[100001];

int result = 0;
int vertexCount = 0;
int endNum = 0;

void postorder(int _cur) {
	--vertexCount;
	if (l[_cur] != -1) {
		++result;
		postorder(l[_cur]);
	}
	if (r[_cur] != -1) {
		++result;
		postorder(r[_cur]);
	}
	if (_cur == endNum && vertexCount == 0) cout << result;
	++result;
}

void inorder(int _cur) {
	if (l[_cur] != -1) inorder(l[_cur]);
	--vertexCount;
	if (vertexCount == 0) endNum = _cur;
	if (r[_cur] != -1) inorder(r[_cur]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(l, l + 100001, -1);
	fill(r, r + 100001, -1);

	int n;
	cin >> n;
	vertexCount = n;

	for (int i = 0; i < n; ++i) {
		int num1, num2, num3;
		cin >> num1 >> num2 >> num3;
		l[num1] = num2;
		r[num1] = num3;
	}
	inorder(1);
	vertexCount = n;
	postorder(1);

	return 0;
}