#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;

	getline(cin, s);

	stack<char> processStack;
	int stickNum = 0;
	int stickResult = 0;

	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == ')') {
			if (i != 0 && s[i - 1] == '(') {
				stickResult += stickNum;
			}
			else if(i != 0 && s[i - 1] == ')'){
				--stickNum;
			}
		}
		else if (s[i] == '(') {
			if (i + 1 != s.size() && s[i + 1] != ')') {
				++stickNum;
				++stickResult;
			}			
		}
	}

	cout << stickResult;
}