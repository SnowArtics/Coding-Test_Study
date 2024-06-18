#include <bits/stdc++.h>

using namespace std;

int l[26];
int r[26];

char check;

void preorder(int _start) {
	char out = _start + 'A';
	cout << out;
	if(l[_start] != check) preorder(l[_start]);
	if(r[_start] != check) preorder(r[_start]);
}

void inorder(int _start) {
	char out = _start + 'A';
	if(l[_start] != check) inorder(l[_start]);
	cout << out;
	if(r[_start] != check) inorder(r[_start]);
}

void postorder(int _start) {
	char out = _start + 'A';
	if(l[_start] != check) postorder(l[_start]);
	if(r[_start] != check) postorder(r[_start]);
	cout << out;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	check = '.' - 'A';

	fill(l, l + 26, check);
	fill(r, r + 26, check);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		char num1, num2, num3;
		cin >> num1 >> num2 >> num3;
		num1 -= 'A';
		num2 -= 'A';
		num3 -= 'A';

		l[num1] = num2;
		r[num1] = num3;
	}

	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);

	return 0;
}