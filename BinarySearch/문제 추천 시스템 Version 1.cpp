#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	map<int, int> problemSet;
	set<int> difficulty[101];

	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int problemNum, problemDif;
		cin >> problemNum >> problemDif;
		problemSet[problemNum] = problemDif;
		difficulty[problemDif].insert(problemNum);
	}

	cin >> m;

	for (int i = 0; i < m; ++i) {
		string operation;
		cin >> operation;

		if (operation == "add") {
			int problemNum, problemDif;
			cin >> problemNum >> problemDif;
			problemSet[problemNum] = problemDif;
			difficulty[problemDif].insert(problemNum);
		}
		else if (operation == "recommend") {
			if (problemSet.size() == 0)
				continue;
			int num;
			cin >> num;
			if (num == 1) {
				for (int i = 100; i >0; --i) {
					if (difficulty[i].size() == 0)
						continue;
					cout << *(prev(difficulty[i].end())) << "\n";
					break;
				}
			}
			else if (num == -1) {
				for (int i = 1; i < 101; ++i) {
					if (difficulty[i].size() == 0)
						continue;
					cout << *(difficulty[i].begin()) << "\n";
					break;
				}
			}
		}
		else if (operation == "solved") {
			int problemNum;
			cin >> problemNum;
			difficulty[problemSet.find(problemNum)->second].erase(problemNum);
			problemSet.erase(problemNum);
		}
	}
}