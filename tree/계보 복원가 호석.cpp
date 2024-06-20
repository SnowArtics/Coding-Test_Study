#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<string, int> sMap;
string peopleList[1001];
int indegree[1001];
vector<int> relationList[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n;

	for (int i = 1; i < n + 1; ++i) {
		string s;
		cin >> s;
		peopleList[i] = s;
	}

	sort(peopleList + 1, peopleList + n + 1);

	for (int i = 1; i < n + 1; ++i) {
		sMap.insert(make_pair(peopleList[i], i));
	}

	cin >> m;

	for (int i = 0; i < m; ++i) {
		string s1, s2;
		cin >> s1 >> s2;
		
		relationList[sMap.find(s2)->second].push_back(sMap.find(s1)->second);
		indegree[sMap.find(s1)->second]++;
	}

	vector<string> parentList;
	for (int i = 1; i < n + 1; ++i)
		if (indegree[i] == 0) parentList.push_back(peopleList[i]);

	cout << parentList.size() << "\n";
	for (auto a : parentList)
		cout << a << " ";
	cout << "\n";

	for (int i = 1; i < n + 1; ++i) {
		cout << peopleList[i] << " ";
		vector<int> outList;
		for (auto a : relationList[i]) {
			if (indegree[a] - indegree[i] == 1) outList.push_back(a);
		}
		sort(outList.begin(), outList.end());
		cout << outList.size() << " ";
		for (auto a : outList)
			cout << peopleList[a] << " ";
		cout << "\n";
	}

	return 0;
}