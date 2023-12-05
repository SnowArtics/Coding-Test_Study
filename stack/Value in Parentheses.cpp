#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;

	getline(cin, s);

	vector<char> processStack;
	stack<int> plusValueStack;// 더하기를 진행할 값들 저장

	for (int i = 0; i < s.size(); ++i) {
		if (processStack.size() == 0 && (s[i] == ')' || s[i] == ']')) {
			cout << 0;
			return 0;
		}

		if (s[i] == '(') {
			processStack.push_back(s[i]);
		}
		else if (s[i] == '[') {
			processStack.push_back(s[i]);
		}
		else if (s[i] == ')') {
			if (processStack.back() == '[') {
				cout << 0;
				return 0;
			}
			else if (processStack.back() == '(' && i != s.size() - 1 && (s[i + 1] == '(' || s[i + 1] == '[')&&(s[i-1]!=']'&&s[i-1]!=')')) {
				int mulResult = 1;
				for (int j = processStack.size()-1; j > -1; --j) {
					if (processStack[j] == '(')
						mulResult *= 2;
					else if (processStack[j] == '[') {
						mulResult *= 3;
					}
				}
				processStack.pop_back();
				plusValueStack.push(mulResult);
			}
			else if (processStack.back() == '(' && i != s.size() - 1 && (s[i + 1] == ')' || s[i + 1] == ']')&&s[i-1]=='(' && (s[i - 1] != ']' && s[i - 1] != ')')) {
				int mulResult = 1;
				for (int j = processStack.size() - 1; j > -1; --j) {
					if (processStack[j] == '(')
						mulResult *= 2;
					else if (processStack[j] == '[') {
						mulResult *= 3;
					}
				}
				processStack.pop_back();
				plusValueStack.push(mulResult);
			}
			else if (processStack.size() == 1 && processStack.back() == '('&&i==s.size()-1 && s[i - 1] == '(') {
				processStack.pop_back();
				plusValueStack.push(2);
			}
			else {
				processStack.pop_back();
			}
		}
		else if (s[i] == ']') {
			if (processStack.back() == '(') {
				cout << 0;
				return 0;
			}
			else if (processStack.back() == '[' && i != s.size() - 1 && (s[i + 1] == '(' || s[i + 1] == '[') && (s[i - 1] != ']' && s[i - 1] != ')')) {
				int mulResult = 1;
				for (int j = processStack.size() - 1; j > -1; --j) {
					if (processStack[j] == '(')
						mulResult *= 2;
					else if (processStack[j] == '[') {
						mulResult *= 3;
					}
				}
				processStack.pop_back();
				plusValueStack.push(mulResult);
			}
			else if (processStack.back() == '[' && i != s.size() - 1 && (s[i + 1] == ')' || s[i + 1] == ']') && s[i - 1] == '[' && (s[i - 1] != ']' && s[i - 1] != ')')) {
				int mulResult = 1;
				for (int j = processStack.size() - 1; j > -1; --j) {
					if (processStack[j] == '(')
						mulResult *= 2;
					else if (processStack[j] == '[') {
						mulResult *= 3;
					}
				}
				processStack.pop_back();
				plusValueStack.push(mulResult);
			}
			else if (processStack.size() == 1 && processStack.back() == '[' && i == s.size() - 1 && s[i-1] == '[') {
				processStack.pop_back();
				plusValueStack.push(3);
			}
			else {
				processStack.pop_back();
			}
		}
	}

	if (processStack.size() != 0) {
		cout << 0;
		return 0;
	}

	int result = 0;
	for (int i = 0; i < plusValueStack.size();) {
		result += plusValueStack.top();
		plusValueStack.pop();
	}

	cout << result;
}